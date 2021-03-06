/**
 * Copyright (c) 2011-2013 by Andrew Mustun. All rights reserved.
 * 
 * This file is part of the QCAD project.
 *
 * QCAD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QCAD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QCAD.
 */

include("Edit.js");

/**
 * Base class for copy and cut.
 */
function ClipboardOperation(guiAction) {
    Edit.call(this, guiAction);

    this.cut = false;
    this.chooseReferencePoint = false;
    this.offset = 0.0;
}

ClipboardOperation.prototype = new Edit();

ClipboardOperation.prototype.beginEvent = function() {
    Edit.prototype.beginEvent.call(this);

    if (this.chooseReferencePoint) {
        this.getDocumentInterface().setClickMode(RAction.PickCoordinate);
        this.setCrosshairCursor();
        var trReferencePoint = qsTr("Reference point");
        var appWin = RMainWindowQt.getMainWindow();
        this.setCommandPrompt(trReferencePoint);
        this.setLeftMouseTip(trReferencePoint);
        this.setRightMouseTip(EAction.trCancel);
        EAction.showSnapTools();
    }
    else {
        this.applyOperation();
        this.terminate();
    }
};

ClipboardOperation.prototype.coordinateEvent = function(event) {
    var di = this.getDocumentInterface();
    di.setRelativeZero(event.getModelPosition());
    this.offset = event.getModelPosition().getNegated();
    this.applyOperation();
    this.terminate();
};

/**
 * Center of the selection is the reference point by default.
 */
ClipboardOperation.prototype.getOffset = function() {
    if (this.chooseReferencePoint) {
        return this.offset;
    }
    else {
        return this.getDocument().getSelectionBox().getCenter().getNegated();
    }
};

/**
 * \return the appropriate operation (copy or cut).
 */
ClipboardOperation.prototype.getOperation = function(preview) {
    return new RCopyOperation(this.getOffset(), this.getDocument());
};

/**
 * Applies the operation returned by this.getOperation.
 */
ClipboardOperation.prototype.applyOperation = function() {
    RDocumentInterface.getClipboard().getDocument().setUnit(this.getDocument().getUnit());
    RDocumentInterface.getClipboard().applyOperation(this.getOperation(false));
    RDocumentInterface.getClipboard().getDocument().setUnit(this.getDocument().getUnit());
    RDocumentInterface.getClipboard().autoZoom();

    if (this.cut) {
        var op = new RDeleteSelectionOperation();
        this.getDocumentInterface().applyOperation(op);
    }
};
