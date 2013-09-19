#if !defined(OBJREAD_HPP)
#define OBJREAD_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>
#include "vertex.hpp"

class objread
{
public:
    objread(const std::string &fname)
    {
        readFile(fname);
    }

    const std::vector<position> & getVerts() const
    {
        return verts;
    }

    const std::vector<normal> &getNormals() const
    {
        return nmls;
    }

    const std::vector<texcoords> &getTexCoords() const
    {
        return uvs;
    }

    const std::vector<triangle> &getTriangles() const
    {
        return tris;
    }

private:
    bool readFile(const std::string &fname)
    {
        std::ifstream objfile(fname.c_str());
        std::string line, tmp;

        while(!objfile.eof())
        {
            getline(objfile, line);
            std::istringstream strm(line);

            strm >> tmp;

            if(tmp == "v")
            {
                position p;

                strm >> p.px >> p.py >> p.pz;

                verts.push_back(p);
            }
            else if(tmp == "vt")
            {
                texcoords st;

                strm >> st.s >> st.t;

                uvs.push_back(st);
            }
            else if(tmp == "vn")
            {
                // ignore for now
            }
            else if(tmp == "f")
            {
                // All faces are assumed to be triangles
                // I may change this later to be more flexible.
                triangle t;
                std::string v0, v1, v2;
                int pi, ti;

                strm >> v0 >> v1 >> v2;

                // Obj indices are not 0-based, so compensate by decrementing the value.
                //std::sscanf( v0.c_str(), "%d/%d", &(t.pos[0]), &(t.tex[0]) );
                std::sscanf( v0.c_str(), "%d/%d", &pi, &ti );
                t.pos[0] = --pi;
                t.tex[0] = --ti;

                std::sscanf( v1.c_str(), "%d/%d", &pi, &ti );
                t.pos[1] = --pi;
                t.tex[1] = --ti;

                std::sscanf( v2.c_str(), "%d/%d", &pi, &ti );
                t.pos[2] = --pi;
                t.tex[2] = --ti;

                tris.push_back(t);
            }
        }

        return bool();
    }

private:
    std::vector<position> verts;
    std::vector<normal> nmls;
    std::vector<texcoords> uvs;

    std::vector<triangle> tris;
};

#endif // end include guard
