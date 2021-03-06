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

#ifndef RIMAGEENTITY_H
#define RIMAGEENTITY_H

#include "entity_global.h"

#include "REntity.h"
#include "RImageData.h"

class RDocument;
class RExporter;

/**
 * Point entity.
 *
 * \scriptable
 * \sharedPointerSupport
 * \ingroup entity
 */
class QCADENTITY_EXPORT RImageEntity: public REntity {

public:
    static RPropertyTypeId PropertyCustom;
    static RPropertyTypeId PropertyHandle;
    static RPropertyTypeId PropertyType;
    static RPropertyTypeId PropertyBlock;
    static RPropertyTypeId PropertyLayer;
    static RPropertyTypeId PropertyLinetype;
    static RPropertyTypeId PropertyLineweight;
    static RPropertyTypeId PropertyColor;
    static RPropertyTypeId PropertyDrawOrder;

    static RPropertyTypeId PropertyFileName;
    static RPropertyTypeId PropertyInsertionPointX;
    static RPropertyTypeId PropertyInsertionPointY;
    static RPropertyTypeId PropertyInsertionPointZ;
    static RPropertyTypeId PropertyScaleFactorX;
    static RPropertyTypeId PropertyScaleFactorY;
    static RPropertyTypeId PropertyAngle;

    static RPropertyTypeId PropertyWidth;
    static RPropertyTypeId PropertyHeight;

public:
    RImageEntity(RDocument* document, const RImageData& data,
        RObject::Id objectId = RObject::INVALID_ID);
    virtual ~RImageEntity();

    static void init();

    virtual RImageEntity* clone() const;

    virtual RS::EntityType getType() const {
        return RS::EntityImage;
    }

    bool setProperty(RPropertyTypeId propertyTypeId, const QVariant& value,
        RTransaction* transaction=NULL);
    QPair<QVariant, RPropertyAttributes> getProperty(
            RPropertyTypeId& propertyTypeId,
            bool humanReadable = false, bool noAttributes = false);

    virtual void exportEntity(RExporter& e, bool preview=false) const;

    virtual RImageData& getData() {
        return data;
    }

    virtual const RImageData& getData() const {
        return data;
    }

    QString getFileName() const {
        return data.getFileName();
    }

    void setFileName(const QString& fn) {
        data.setFileName(fn);
    }

    RVector getInsertionPoint() const {
        return data.getInsertionPoint();
    }

    void setInsertionPoint(const RVector& ip) {
        data.setInsertionPoint(ip);
    }

    RVector getUVector() const {
        return data.getUVector();
    }

    RVector getVVector() const {
        return data.getVVector();
    }

    int getBrightness() const {
        return data.getBrightness();
    }

    int getContrast() const {
        return data.getContrast();
    }

    int getFade() const {
        return data.getFade();
    }

    void setWidth(double w, bool keepRatio=false) {
        data.setWidth(w, keepRatio);
    }

    void setHeight(double h, bool keepRatio=false) {
        data.setHeight(h, keepRatio);
    }

    void setAngle(double a) {
        data.setAngle(a);
    }

    double getWidth() const {
        return data.getWidth();
    }

    double getHeight() const {
        return data.getHeight();
    }

    int getPixelWidth() const {
        return data.getPixelWidth();
    }

    int getPixelHeight() const {
        return data.getPixelHeight();
    }

protected:
    virtual void print(QDebug dbg) const;

protected:
    RImageData data;
};

Q_DECLARE_METATYPE(RImageEntity*)
Q_DECLARE_METATYPE(QSharedPointer<RImageEntity>)
Q_DECLARE_METATYPE(QSharedPointer<RImageEntity>*)

#endif
