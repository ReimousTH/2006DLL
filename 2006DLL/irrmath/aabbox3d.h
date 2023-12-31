 // Copyright (C) 2002-2012 Nikolaus Gebhardt
 // This file is part of the "Irrlicht Engine".
 // For conditions of distribution and use, see copyright notice in irrlicht.h
 
 #ifndef __IRR_AABBOX_3D_H_INCLUDED__
 #define __IRR_AABBOX_3D_H_INCLUDED__
 
 #include "irrMath.h"
 #include "plane3d.h"
 #include "line3d.h"
 
 namespace irr
 {
 namespace core
 {
 
 
 template <class T>
 class aabbox3d
 {
     public:
 
         aabbox3d(): MinEdge(-1,-1,-1), MaxEdge(1,1,1) {}
         aabbox3d(const vector3d<T>& min, const vector3d<T>& max): MinEdge(min), MaxEdge(max) {}
         aabbox3d(const vector3d<T>& init): MinEdge(init), MaxEdge(init) {}
         aabbox3d(T minx, T miny, T minz, T maxx, T maxy, T maxz): MinEdge(minx, miny, minz), MaxEdge(maxx, maxy, maxz) {}
 
         // operators
 
         inline bool operator==(const aabbox3d<T>& other) const { return (MinEdge == other.MinEdge && other.MaxEdge == MaxEdge);}
 
         inline bool operator!=(const aabbox3d<T>& other) const { return !(MinEdge == other.MinEdge && other.MaxEdge == MaxEdge);}
 
         // functions
 
 
         void reset(T x, T y, T z)
         {
             MaxEdge.set(x,y,z);
             MinEdge = MaxEdge;
         }
 
 
         void reset(const aabbox3d<T>& initValue)
         {
             *this = initValue;
         }
 
 
         void reset(const vector3d<T>& initValue)
         {
             MaxEdge = initValue;
             MinEdge = initValue;
         }
 
 
         void addInternalPoint(const vector3d<T>& p)
         {
             addInternalPoint(p.X, p.Y, p.Z);
         }
 
 
         void addInternalBox(const aabbox3d<T>& b)
         {
             addInternalPoint(b.MaxEdge);
             addInternalPoint(b.MinEdge);
         }
 
 
         void addInternalPoint(T x, T y, T z)
         {
             if (x>MaxEdge.X) MaxEdge.X = x;
             if (y>MaxEdge.Y) MaxEdge.Y = y;
             if (z>MaxEdge.Z) MaxEdge.Z = z;
 
             if (x<MinEdge.X) MinEdge.X = x;
             if (y<MinEdge.Y) MinEdge.Y = y;
             if (z<MinEdge.Z) MinEdge.Z = z;
         }
 
 
         vector3d<T> getCenter() const
         {
             return (MinEdge + MaxEdge) / 2;
         }
 
 
         vector3d<T> getExtent() const
         {
             return MaxEdge - MinEdge;
         }
 
 
         bool isEmpty() const
         {
             return MinEdge.equals ( MaxEdge );
         }
 
         T getVolume() const
         {
             const vector3d<T> e = getExtent();
             return e.X * e.Y * e.Z;
         }
 
         T getArea() const
         {
             const vector3d<T> e = getExtent();
             return 2*(e.X*e.Y + e.X*e.Z + e.Y*e.Z);
         }
 
 
         void getEdges(vector3d<T> *edges) const
         {
             const core::vector3d<T> middle = getCenter();
             const core::vector3d<T> diag = middle - MaxEdge;
 
             /*
             Edges are stored in this way:
             Hey, am I an ascii artist, or what? :) niko.
                    /3--------/7
                   / |       / |
                  /  |      /  |
                 1---------5   |
                 |  /2- - -|- -6
                 | /       |  /
                 |/        | /
                 0---------4/
             */
 
             edges[0].set(middle.X + diag.X, middle.Y + diag.Y, middle.Z + diag.Z);
             edges[1].set(middle.X + diag.X, middle.Y - diag.Y, middle.Z + diag.Z);
             edges[2].set(middle.X + diag.X, middle.Y + diag.Y, middle.Z - diag.Z);
             edges[3].set(middle.X + diag.X, middle.Y - diag.Y, middle.Z - diag.Z);
             edges[4].set(middle.X - diag.X, middle.Y + diag.Y, middle.Z + diag.Z);
             edges[5].set(middle.X - diag.X, middle.Y - diag.Y, middle.Z + diag.Z);
             edges[6].set(middle.X - diag.X, middle.Y + diag.Y, middle.Z - diag.Z);
             edges[7].set(middle.X - diag.X, middle.Y - diag.Y, middle.Z - diag.Z);
         }
 
 
         void repair()
         {
             T t;
 
             if (MinEdge.X > MaxEdge.X)
                 { t=MinEdge.X; MinEdge.X = MaxEdge.X; MaxEdge.X=t; }
             if (MinEdge.Y > MaxEdge.Y)
                 { t=MinEdge.Y; MinEdge.Y = MaxEdge.Y; MaxEdge.Y=t; }
             if (MinEdge.Z > MaxEdge.Z)
                 { t=MinEdge.Z; MinEdge.Z = MaxEdge.Z; MaxEdge.Z=t; }
         }
 
 
         aabbox3d<T> getInterpolated(const aabbox3d<T>& other, f32 d) const
         {
             f32 inv = 1.0f - d;
             return aabbox3d<T>((other.MinEdge*inv) + (MinEdge*d),
                 (other.MaxEdge*inv) + (MaxEdge*d));
         }
 
 
         bool isPointInside(const vector3d<T>& p) const
         {
             return (p.X >= MinEdge.X && p.X <= MaxEdge.X &&
                 p.Y >= MinEdge.Y && p.Y <= MaxEdge.Y &&
                 p.Z >= MinEdge.Z && p.Z <= MaxEdge.Z);
         }
 
 
         bool isPointTotalInside(const vector3d<T>& p) const
         {
             return (p.X > MinEdge.X && p.X < MaxEdge.X &&
                 p.Y > MinEdge.Y && p.Y < MaxEdge.Y &&
                 p.Z > MinEdge.Z && p.Z < MaxEdge.Z);
         }
 
 
         bool isFullInside(const aabbox3d<T>& other) const
         {
             return (MinEdge.X >= other.MinEdge.X && MinEdge.Y >= other.MinEdge.Y && MinEdge.Z >= other.MinEdge.Z &&
                 MaxEdge.X <= other.MaxEdge.X && MaxEdge.Y <= other.MaxEdge.Y && MaxEdge.Z <= other.MaxEdge.Z);
         }
 
 
         bool intersectsWithBox(const aabbox3d<T>& other) const
         {
             return (MinEdge.X <= other.MaxEdge.X && MinEdge.Y <= other.MaxEdge.Y && MinEdge.Z <= other.MaxEdge.Z &&
                 MaxEdge.X >= other.MinEdge.X && MaxEdge.Y >= other.MinEdge.Y && MaxEdge.Z >= other.MinEdge.Z);
         }
 
 
         bool intersectsWithLine(const line3d<T>& line) const
         {
             return intersectsWithLine(line.getMiddle(), line.getVector().normalize(),
                     (T)(line.getLength() * 0.5));
         }
 
 
         bool intersectsWithLine(const vector3d<T>& linemiddle,
                     const vector3d<T>& linevect, T halflength) const
         {
             const vector3d<T> e = getExtent() * (T)0.5;
             const vector3d<T> t = getCenter() - linemiddle;
 
             if ((fabs(t.X) > e.X + halflength * fabs(linevect.X)) ||
                 (fabs(t.Y) > e.Y + halflength * fabs(linevect.Y)) ||
                 (fabs(t.Z) > e.Z + halflength * fabs(linevect.Z)) )
                 return false;
 
             T r = e.Y * (T)fabs(linevect.Z) + e.Z * (T)fabs(linevect.Y);
             if (fabs(t.Y*linevect.Z - t.Z*linevect.Y) > r )
                 return false;
 
             r = e.X * (T)fabs(linevect.Z) + e.Z * (T)fabs(linevect.X);
             if (fabs(t.Z*linevect.X - t.X*linevect.Z) > r )
                 return false;
 
             r = e.X * (T)fabs(linevect.Y) + e.Y * (T)fabs(linevect.X);
             if (fabs(t.X*linevect.Y - t.Y*linevect.X) > r)
                 return false;
 
             return true;
         }
 
 
         EIntersectionRelation3D classifyPlaneRelation(const plane3d<T>& plane) const
         {
             vector3d<T> nearPoint(MaxEdge);
             vector3d<T> farPoint(MinEdge);
 
             if (plane.Normal.X > (T)0)
             {
                 nearPoint.X = MinEdge.X;
                 farPoint.X = MaxEdge.X;
             }
 
             if (plane.Normal.Y > (T)0)
             {
                 nearPoint.Y = MinEdge.Y;
                 farPoint.Y = MaxEdge.Y;
             }
 
             if (plane.Normal.Z > (T)0)
             {
                 nearPoint.Z = MinEdge.Z;
                 farPoint.Z = MaxEdge.Z;
             }
 
             if (plane.Normal.dotProduct(nearPoint) + plane.D > (T)0)
                 return ISREL3D_FRONT;
 
             if (plane.Normal.dotProduct(farPoint) + plane.D > (T)0)
                 return ISREL3D_CLIPPED;
 
             return ISREL3D_BACK;
         }
 
         vector3d<T> MinEdge;
 
         vector3d<T> MaxEdge;
 };
 
     typedef aabbox3d<f32> aabbox3df;
     typedef aabbox3d<s32> aabbox3di;
 
 } // end namespace core
 } // end namespace irr
 
 #endif
 
