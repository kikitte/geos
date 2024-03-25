/**********************************************************************
 *
 * GEOS - Geometry Engine Open Source
 * http://geos.osgeo.org
 *
 * Copyright (C) 2024 ISciences, LLC
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation.
 * See the COPYING file for more information.
 *
 **********************************************************************/

#pragma once

#include <geos/geom/SurfaceImpl.h>

namespace geos {
namespace geom {

class GEOS_DLL CurvePolygon : public SurfaceImpl<Curve> {
    friend class GeometryFactory;

public:
    ~CurvePolygon() override = default;

    std::unique_ptr<CoordinateSequence> getCoordinates() const override;

    int
    getSortIndex() const override
    {
        return SORTINDEX_CURVEPOLYGON;
    }

    std::string getGeometryType() const override;

    GeometryTypeId getGeometryTypeId() const override;

    std::unique_ptr<Geometry> getBoundary() const override;

    void normalize() override;

    double getArea() const override;

    bool hasCurvedComponents() const override;

protected:
    using SurfaceImpl::SurfaceImpl;

    Geometry* cloneImpl() const override;

    Geometry* reverseImpl() const override;
};


}
}
