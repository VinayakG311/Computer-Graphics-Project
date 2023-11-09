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

void Cage::createGrid()
{
    float stepx = (max_x_coord - min_x_coord) / 100;
    float stepy = (max_y_coord - min_y_coord) / 100;
    bool breaker = false;

    float changeInval = 0;
    int numOfcoord = 0;

    while (true)
    {
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
                if (coord_x == max_x_coord || coord_x == min_x_coord || coord_y == min_y_coord || coord_y == max_y_coord)
                {
                    // Exterior/Boundary

                    grid[i][j] = 1;
                    
                }
                else
                {
                    // Interior
                    numOfcoord++;
                    float prev = grid[i][j];

                    float check = 0;
                    int neighbors = 0;
                    if(i>0){
                        check+=grid[i-1][j];
                        neighbors++;
                        
                    }
                    if(j>0){
                        check+=grid[i][j-1];
                        neighbors++;
                        
                    }
                    check+=(grid[i][j+1]+grid[i+1][j]);
                    neighbors+=2;
                   
                    // grid[i][j] = (grid[i - 1][j] + grid[i][j - 1] + grid[i + 1][j] + grid[i][j + 1]) / 4;

                    grid[i][j] = check / (float)neighbors;
                    // std::cout<<grid[i][j]<<" ";
                    changeInval+=abs(grid[i][j] - prev);
                  
                }
            }
        }
        // std::cout<<changeInval<<" ";
        if( ((changeInval) / (float)numOfcoord) < 0.001f ){
            breaker = true;
            break;
        }
    }

    // for(int i = 0;i<100;i++){
    //     for(int j = 0;j<100;j++){
    //         std::cout<<grid[i][j]<<"\n";
    //     }
    // }
}
