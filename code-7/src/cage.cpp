#include "cage.hpp"

int Cage::createCage(unsigned int &program, unsigned int &obj_VAO, vector<float> &points)
{
    glUseProgram(program);

    // Bind shader variables
    int vVertex_attrib = glGetAttribLocation(program, "vVertex");
    if (vVertex_attrib == -1)
    {
        fprintf(stderr, "Could not bind location: vVertex\n");
        exit(0);
    }

    std::vector<float> v;
    cage.push_back(min_x_coord - 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(max_z_coord + 0.2);

    std::vector<float> cubicBezier;

    bool first = true;
    int sz = cage.size(); // Contains 3 points/vertex. Ignore Z
    float x[4], y[4], z[4];
    float delta_t = 1.0 / (100.0 - 1.0);
    float t;
    float prevX, prevY;

    for (int i = 0; i < (sz - 3); i += 3)
    {
        x[0] = cage[i];
        y[0] = cage[i + 1];
        z[0] = cage[i + 2];
        x[3] = cage[i + 3];
        y[3] = cage[i + 4];
        z[3] = cage[i + 5];
        cubicBezier.push_back(x[0]);
        cubicBezier.push_back(y[0]);
        cubicBezier.push_back(z[0]);
        controlPoints.push_back(x[0]);
        controlPoints.push_back(y[0]);
        controlPoints.push_back(z[0]);
    }

    cubicBezier.push_back(x[3]);
    cubicBezier.push_back(y[3]);
    cubicBezier.push_back(z[3]);
    controlPoints.push_back(x[3]);
    controlPoints.push_back(y[3]);
    controlPoints.push_back(z[3]);

    glGenVertexArrays(1, &obj_VAO);
    glBindVertexArray(obj_VAO);
    GLuint vertex_VBO;
    // cout << v.size() << endl;

    glGenBuffers(1, &vertex_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
    glBufferData(GL_ARRAY_BUFFER, cubicBezier.size() * sizeof(GLfloat), &cubicBezier[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    for (auto i : controlPoints)
    {
        points.push_back(i);
    }

    return cubicBezier.size();
}

// 3_________________2
// |                |
// |                |
// |                |
// |                |
// |                |
// |                |
// |________________|
// 0                1
void Cage::handleEdge(int currEdge, int i, int j, float x, float y)
{
    float valy, valx;
    float dfx = max_x_coord - min_x_coord;
    float dfy = max_y_coord - min_y_coord;
    
    if (currEdge == 0)
    {
       
        // previos edge
        if (x == min_x_coord && y < max_y_coord)
        {
            harmonic[currEdge][i][j] = (100-j) * 0.01;
        }

        // next edge
        if (y == min_y_coord && x < max_x_coord)
        {
            
            harmonic[currEdge][i][j] = (100 - i) * 0.01;
        }
    }

    else if (currEdge == 1)
    {

        if (y == min_y_coord && x<max_x_coord)
        {
            harmonic[currEdge][i][j] = (i) * 0.01;
        }

        // next edge
        if (x == max_x_coord && y <max_y_coord)
        {
            harmonic[currEdge][i][j] = (j) * 0.01;
        }
    }

    else if (currEdge == 2)
    {
        // prev edge
    
        if (x == max_x_coord && y < max_y_coord)
        {
            harmonic[currEdge][i][j] = (100-j) * 0.01;
        }

        // next edge
        if (y == max_y_coord && x < max_x_coord)
        {
            harmonic[currEdge][i][j] = (i) * 0.01;
        }
    }

    else if (currEdge == 3)
    {
        // prev edge
        if (y == max_y_coord && x != min_x_coord && x != max_x_coord)
        {
            harmonic[currEdge][i][j] = (100 - i) * 0.01;
        }

        // next edge
        if (x == min_x_coord && y != min_y_coord && y != max_y_coord)
        {
            harmonic[currEdge][i][j] = (j) * 0.01;
        }
    }

    // cout<<harmonic[currEdge][x][y]<<endl;
}
// void Cage::handleEdge(int currEdge, int i,int j,float x, float y)
// {
//     float valy,valx;
//     float dfx = max_x_coord - min_x_coord;
//     float dfy = max_y_coord - min_y_coord;
//     if (currEdge == 0)
//     {
//         // previos edge
//         if (x == min_x_coord && y != min_y_coord && y != max_y_coord)
//         {
//             harmonic[currEdge][i][j] = (max_y_coord - y)/dfy;
//         }

//         // next edge
//         if (y == min_y_coord && x != min_x_coord && x != max_x_coord)
//         {
//             harmonic[currEdge][i][j] = (x-min_x_coord)/dfx;
//         }
//     }

//     else if (currEdge == 1)
//     {
//         // prevEdge
//         if (y == min_y_coord && x != min_x_coord && x != max_x_coord)
//         {
//             harmonic[currEdge][i][j] = (max_x_coord-x)/dfx;
//         }

//         // next edge
//         if (x == max_x_coord && y != min_y_coord && y != max_y_coord)
//         {
//             harmonic[currEdge][i][j] = (y-min_y_coord)/dfy;
//         }
//     }

//     else if (currEdge == 2)
//     {
//         // prev edge
//         if (x == max_x_coord && y != min_y_coord && y != max_y_coord)
//         {
//             harmonic[currEdge][i][j] = (max_y_coord-y)/dfy;
//         }

//         // next edge
//         if (y == max_y_coord && x != min_x_coord && x != max_x_coord)
//         {
//             harmonic[currEdge][i][j] = (max_x_coord-x)/dfx;
//         }
//     }

//     else if (currEdge == 3)
//     {
//         // prev edge
//         if (y == max_y_coord && x != min_x_coord && x != max_x_coord)
//         {
//             harmonic[currEdge][i][j] = (x-min_x_coord)/dfx;
//         }

//         // next edge
//         if (x == min_x_coord && y != min_y_coord && y != max_y_coord)
//         {
//             harmonic[currEdge][i][j] = (max_y_coord - y)/dfy;
//         }
//     }

//     // cout<<harmonic[currEdge][x][y]<<endl;
// }

// void Cage::createGrid()
// {
//     float stepx = (max_x_coord - min_x_coord) / 100;
//     float stepy = (max_y_coord - min_y_coord) / 100;
//     bool breaker = false;

//     float changeInval = 0;
//     int numOfcoord = 0;

//     while (true)
//     {
//         if (breaker)
//         {
//             break;
//         }

//         for(int i = 0;i<4;i++){
//              changeInval = 0.0f;
//              numOfcoord = 0;

//             for (int j = 0; j <= 100; j++)
//             {
//                 for (int k = 0; k <= 100; k++)
//                 {
//                     float coord_x = (bottomboundayVertexX + j * stepx);
//                     float coord_y = (bottomboundayVertexY + k * stepy);

//                 // Boundary vertex of cage
//                     if((coord_x == topboundayVertexX && coord_y == topboundayVertexY) || (coord_x == topboundayVertexX && coord_y == bottomboundayVertexY) || (coord_x == bottomboundayVertexX && coord_y == topboundayVertexY) || (coord_x == bottomboundayVertexX && coord_y == bottomboundayVertexY)  ){
//                         // for(int i = 0;i<4;i++){
//                         //     for(int j = 0;j<100;j++){
//                         //         for(int k = 0;k<100;k++){
//                         //             harmonic[i][j][k] = 1.0f;
//                         //         }
//                         //     }
//                         // }

//                         harmonic[i][j][k] = 1.0f;
//                     }

//                     // Edge
//                     else if( coord_x == topboundayVertexX || coord_x == bottomboundayVertexX || coord_y == topboundayVertexY || coord_y == bottomboundayVertexY){
//                         handleEdge(i,coord_x,coord_y);
//                     }

//                     else{

//                     //    cout<<"Here"<<" ";
//                         // Interior
//                         numOfcoord++;
//                         float prev = harmonic[i][j][k];

//                         float check = 0;
//                         int neighbors = 0;
//                         if (j > 0)
//                         {
//                             check += harmonic[i][j-1][k];
//                             neighbors++;
//                         }
//                         if (k > 0)
//                         {
//                             check += harmonic[i][j][k-1];
//                             neighbors++;
//                         }
//                         check += (harmonic[i][j][k+1] + harmonic[i][j+1][k]);
//                         neighbors += 2;

//                         // grid[i][j] = (grid[i - 1][j] + grid[i][j - 1] + grid[i + 1][j] + grid[i][j + 1]) / 4;

//                         harmonic[i][j][k] = check / (float)neighbors;
//                         // std::cout<<grid[i][j]<<" ";
//                         changeInval += abs(harmonic[i][j][k] - prev);

//                     }
//                 }
//             }

//              if( numOfcoord > 0 &&  ((changeInval) / (float) numOfcoord) < 0.001f)
//                 {
//                     breaker = true;

//                     for(int i = 0;i<4;i++){
//                         for(int j = 0;j<100;j++){
//                             for(int k = 0;k<100;k++){
//                                 cout<<harmonic[i][j][k]<<"   ";
//                             }
//                         }
//                     }

//                     break;
//                 }

//         }
//         // std::cout<<changeInval<<" ";

//     }
// }
void Cage::createGrid()
{
    float stepx = (max_x_coord - min_x_coord) / 100;
    float stepy = (max_y_coord - min_y_coord) / 100;
    

    float changeInval = 0;
    int numOfcoord = 0;


    for (int k = 0; k < 4; k++)
    {
        int c=0;
        bool breaker = false;
        while (true)
        {   
            c++;
           // cout<<c<<endl;
            if (breaker)
            {
                break;
            }
            changeInval = 0.0f;
            numOfcoord = 0;
            for (int i = 0; i <= 100; i++)
            {
                for (int j = 0; j <= 100; j++)
                {
                    float coord_x = (min_x_coord + i * stepx);
                    float coord_y = (min_y_coord + j * stepy);
                    if ((coord_x == max_x_coord && coord_y == max_y_coord) || (coord_x == max_x_coord && coord_y == min_y_coord) || (coord_x == min_x_coord && coord_y == max_y_coord) || (coord_x == min_x_coord && coord_y == min_y_coord))
                    {
                      
 
                            harmonic[k][i][j] = 1.0f;
                    }
                    // else if (coord_y == max_y_coord || coord_y == min_y_coord)
                    // {
                            
                    //         harmonic[k][i][j] = (100 - i) * 0.01;
                    // }
                    // else if(coord_x==max_x_coord || coord_x == min_x_coord)
                    // {
                        
                    //     harmonic[k][i][j]= (100-j)*0.01;
                    // }
               

                        else if (coord_x == max_x_coord || coord_x == min_x_coord || coord_y == min_y_coord || coord_y == max_y_coord)
                        {
                            // Exterior/Boundary
                            // harmonic[k][i][j] = 1.0f;
                           
                             handleEdge(k,i,j,coord_x,coord_y);
                             
                            
                        }
                        else
                        {
                            // Interior
                            numOfcoord++;
                            float prev = harmonic[k][i][j];

                            float check = 0;
                            int neighbors = 0;
                            if (i > 0)
                            {
                                check += harmonic[k][i - 1][j];
                                neighbors++;
                            }
                            if (j > 0)
                            {
                                check += harmonic[k][i][j - 1];
                                neighbors++;
                            }
                            check += (harmonic[k][i][j + 1] + harmonic[k][i + 1][j]);
                            neighbors += 2;

                            // grid[i][j] = (grid[i - 1][j] + grid[i][j - 1] + grid[i + 1][j] + grid[i][j + 1]) / 4;

                            harmonic[k][i][j] = check / (float)neighbors;
                            
                            // std::cout<<grid[i][j]<<" ";
                            changeInval += abs(harmonic[k][i][j] - prev);
                        }
                    }
            }
            // std::cout<<changeInval<<" ";
            if (((changeInval) / (float)numOfcoord) < 0.001f)
            {
                for(int i = 0;i<=100;i++){
                    std::cout<<harmonic[0][i][0]<<" ";
                }
                breaker = true;
                break;
            }
        }
    }


    
}

bool Cage::RecomputeVertex(vector<GLfloat> &mesh)
{
    int sz = mesh.size();
    for (int i = 0; i < mesh.size() / 3; i++)
    {
        float stepx = (max_x_coord - min_x_coord) / 100;
        float stepy = (max_y_coord - min_y_coord) / 100;
        GLfloat old_x = mesh[i * 3];
        GLfloat old_y = mesh[i * 3 + 1];

        int map_x = (old_x - min_x_coord) / stepx;
        int map_y = (old_y - min_y_coord) / stepy;
        GLfloat new_x, new_y;
        for (int j = 0; j < controlPoints.size() / 3; j++)
        {
            new_x += grid[map_x][map_y] * (controlPoints[j * 3]);
            new_y += grid[map_x][map_y] * (controlPoints[j * 3 + 1]);
        }
        mesh[i * 3] = new_x;
        mesh[i * 3 + 1] = new_y;
    }
    return true;
}