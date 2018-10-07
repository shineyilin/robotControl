
#include "algo.h"

FLOAT32 algo::linearInseert(LIST1D R, LIST1D L, FLOAT32 x)
{
	FLOAT32			length;
	FLOAT32			res;
    static uint_32	start_index;

	length = R.size();
    if (start_index+1  == length) start_index = 0;
	//printf("x = %f index = %f\n",x, start_index);
	for (uint_32 index = start_index; index < length; index++)
	{
		if (x > L[index]) continue;
		else if (index < 0)
		{
			printf("value small then range\n");
			printf("please check the data!!!\n");
			return 0;
		}
		//else if (index == length-1)
		//{
		//	start_index = index;
		//	printf("\t\nlind = %f, %f\n", index, length);
		//	return R[index];
		//}
		else if (R[index]*R[index-1] >= 0)
		{
			res = (x-L[index  ])/(L[index-1]-L[index  ])\
				  *R[index-1]+\
				  (x-L[index-1])/(L[index  ]-L[index-1])\
				  *R[index  ];
			start_index = index;
			return res;
        }
	}
	if (x> L[length-1])
	{
		printf("value large then range\n");
		printf("please check the data!!!\n");
		return 0;
	}
	return 0;
}

void algo::addPointToPointList(POINTLIST &node_list, VECTOR2D node)
{
	node_list.push_back(node);
}
/*********************************************************
 *print a point vector value which means x and y
 ********************************************************/
void algo::printPoint(VECTOR2D node)
{
	FLOAT32 x;
	FLOAT32 y;
	x = node.x;
	y = node.y;
	printf("x = %f, y = %f\n", x, y);
}

/*********************************************************
 * print a point list value
 ********************************************************/
void algo::printPointList(POINTLIST node_list)
{
	VECTOR2D	node;
	uint_32 length;
	length  = node_list.size();
	//current				= current -> next;
	printf("=======point list data =======\n");
	printf("length = %d\n", length);
	for (uint_32 index =0; index < length; index++)
	{
		node = node_list[index];
		printPoint(node);
	}
}

void algo::writePointList(char *file_name, POINTLIST node_list)
{
	FILE *hand = fopen(file_name, "w");
	if (hand == NULL)
	{
		printf("file open error !!!\n");
		return;
	}
	FLOAT32 length;
	FLOAT32 x;
	FLOAT32 y;
	char temp_buff[64];
	length = node_list.size();
	for (uint_32 index = 0; index < length; index++)
	{
		x = node_list[index].x;
		y = node_list[index].y;
		sprintf(temp_buff, "%e %e\n",x,y);
		fprintf(hand, temp_buff);
	}
	fclose(hand);
}
/*********************************************************
 * rotate a point through the center point
 ********************************************************/
VECTOR2D algo::rotatePoint(VECTOR2D &node, FLOAT32 tran_mat[2][2] )
{
	FLOAT32			new_node_mat[2]={};
	VECTOR2D		new_node;
	FLOAT32			node_mat[2];
	node_mat[0]  =  node.x;
	node_mat[1]  =  node.y;

	for (uint_8 row = 0; row < 2; row ++)
	{
		for (uint_8 col = 0; col < 2; col++)
		{
			new_node_mat[row] += tran_mat[row][col]*\
								node_mat[col];
		}
	}
	new_node.x = new_node_mat[0];
	new_node.y = new_node_mat[1];
	node = new_node;
	return new_node;
}
/*********************************************************
 * rotate a point through the center point
 * :input
 *			original node and angle
 * :output
 *			new point
 ********************************************************/
VECTOR2D algo::rotatePoint(VECTOR2D &node, FLOAT32 theta)
{
	VECTOR2D new_node;
	FLOAT32 translate[2][2] ={{cos(theta),-sin(theta)},
							{sin(theta), cos(theta)} };
	new_node = rotatePoint(node, translate);
	return new_node;
}
VECTOR2D algo::movePoint(VECTOR2D &node, VECTOR2D move)
{
	node.x = node.x + move.x;
	node.y = node.y + move.y;
	return node;
}

POINTLIST algo::getTranslatePointList( POINTLIST	&node_list,
								 VECTOR2D	center,
								 FLOAT32		angle		)
{
	FLOAT32		length;
	VECTOR2D	temp;
	VECTOR2D	node;
	temp.x	= -center.x;
	temp.y	= -center.y;

	length  = node_list.size();
	for (uint_32 index = 0; index < length; index++)
	{
		node = movePoint	(node_list[index], temp  );
		node = rotatePoint	(            node, angle );
		node = movePoint	(            node, center);
		node_list[index] = node;
	}
	return node_list;
}

POINTLIST algo::getTranslatePointList( POINTLIST	&node_list,
                                       FLOAT32		theta		)
{
	FLOAT32		length;
	VECTOR2D	node;

	length  = node_list.size();
	for (uint_32 index = 0; index < length; index++)
	{
		node = rotatePoint(node_list[index], theta );
		node_list[index] = node;
	}
	return node_list;
}


POINTLIST algo::addExtrudePointList(	POINTLIST	&node_list,
                                        VECTOR2D	add_node,
                                        FLOAT32		theta      )
{
	FLOAT32 length;
	length = node_list.size();
	for (uint_32 index = 0; index < length; index ++)
	{
		rotatePoint(node_list[index], theta);
		movePoint(node_list[index], add_node);
	}
	node_list.insert(node_list.begin(), add_node);
	return node_list;
}

void algo::extrudeModelCurve(	POINTLIST	&node_list,
                                SPEED2D		speed,
                                FLOAT32		delta_time )
{
	VECTOR2D	add_node;
	FLOAT32		theta;
	theta		= speed.theta;
	add_node.x	= speed.value*cos(theta)*delta_time;
	add_node.y	= speed.value*sin(theta)*delta_time;
	node_list	= addExtrudePointList\
						(node_list,add_node,theta);
}

/********************************************************
 *a : point to model
 *u : point to center line
 * *****************************************************/
SPEED2D algo::extrudeModelSpeed(		FLOAT32	a,
                                        FLOAT32	u,
                                        FLOAT32 v,
                                        FLOAT32	delta_time )
{
	FLOAT32		R;
	FLOAT32		theta;
	SPEED2D		speed;
	if (fabs(a) < fabs(u) ) return speed;
	R = R(a,u);
	theta		= 1./R * v * delta_time;
	speed.value = v;
	speed.theta = theta;
	//printf("temp value=%f, %f \n", speed.value, speed.theta);
	return speed;
}

void algo::unitTest5()
{
	FLOAT32 a;
	FLOAT32 u;
	FLOAT32 v;

	POINTLIST node_list;
	FLOAT32 delta_time = .2;
	SPEED2D speed;
	a = 10;
	u = 10;
	v = 1;
	for (uint_8 t = 0; t < 3; t++)
	{
		speed = extrudeModelSpeed(10,10,1,delta_time);
		printf("value=%f, %f \n", speed.value, speed.theta);
		for (int i = 0; i < 100; i++)
		{
			extrudeModelCurve(node_list, speed, delta_time);
		}

		speed = extrudeModelSpeed(10,0,1,delta_time);
		printf("value=%f, %f \n", speed.value, speed.theta);
		for (int i = 0; i < 100; i++)
		{
			extrudeModelCurve(node_list, speed, delta_time);
		}
		//printPointList( node_list );
		char path[] = "data.txt";
	 	writePointList(path,node_list);
	}
}

void algo::unitTest1()
{
	printf("teanslate point list test...\n");
	VECTOR2D node;
	VECTOR2D center;
	POINTLIST node_list;

	center.x = 9;
	center.y = 1;
	for (uint_8 index = 0; index < 10; index ++)
	{
		node.x = index;
		node.y = 1;
		addPointToPointList(node_list, node);
	}
	printPointList(node_list);
	printPointList( getTranslatePointList( node_list, center, 0.) );
	printPointList( getTranslatePointList( node_list, center, 90.) );
	printPointList( getTranslatePointList( node_list, center, 180.) );
}

void algo::unitTest2()
{
	printf("teanslate point test...\n");
	VECTOR2D node;
	node.x = 1;
	node.y = 0;
	printf("\n");
	printPoint(node);
	printPoint(rotatePoint(node,0.  ) );
	printPoint(rotatePoint(node,90. ) );
	printPoint(rotatePoint(node,180.) );
	printPoint(rotatePoint(node,270.) );
	//printPoint(rotatePoint(node,360.) );
}

void algo::unitTest3()
{
	printf("extrude curve test...\n");
	VECTOR2D node;
	POINTLIST node_list;
	POINTLIST curve;
	for (uint_16 index = 0; index < 10; index++)
	{
		node.x = index;
		node.y = 0;
		addPointToPointList(node_list, node);
	}
	printPointList(node_list);
	SPEED2D speed;
	speed.value = 1;
	speed.theta = 0;
	extrudeModelCurve(curve,speed, 1.);
	speed.value = 1;
	speed.theta = M_PI/2;
	extrudeModelCurve(curve,speed, .5);
	printPointList(curve);
}

void algo::unitTest4()
{

	printf("insert function test...\n");
	LIST1D R;
	LIST1D L;
	L.push_back(0.);
	R.push_back(0.);

	L.push_back(.1);
	R.push_back(.1);

	L.push_back(.2);
	R.push_back(.0);
	for (FLOAT32 x = 0; x < .2; x+=0.01)
	{
		printf("%f ", x);
		printf( "%f \n", linearInseert(R,L,x) );
	}
}
