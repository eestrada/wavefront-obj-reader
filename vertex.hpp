#if !defined(VERTEX_HPP)
#define VERTEX_HPP

#include <ostream>

struct vertex
{
    float px, py, pz;
    float nx, ny, nz;
    float s, t;
};

struct position
{
    float px, py, pz;
};

struct normal
{
    float nx, ny, nz;
};

struct texcoords
{
    float s, t;
};

struct triangle
{
    int pos[3];
    int nml[3];
    int tex[3];
};

inline std::ostream & operator<<(std::ostream &out, position p)
{
    out << "v" << " " << p.px << " " << p.py << " " << p.pz;
    return out;
}

inline std::ostream & operator<<(std::ostream &out, normal n)
{
    out << "vn" << " " << n.nx << " " << n.ny << " " << n.nz;
    return out;
}

inline std::ostream & operator<<(std::ostream &out, texcoords tex)
{
    out << "vt" << " " << tex.s << " " << tex.t << " " << 0.0f;
    return out;
}

inline std::ostream & operator<<(std::ostream &out, triangle t)
{
    out << "f" << " " << t.pos[0] << "/" << t.tex[0] << " ";
    out << t.pos[1] << "/" << t.tex[1] << " ";
    out << t.pos[2] << "/" << t.tex[2];
    return out;
}

#endif // end include guard
