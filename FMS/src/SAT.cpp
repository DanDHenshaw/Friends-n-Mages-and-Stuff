#include "SAT.h"

struct corners
{
	sf::Vector2f topLeftCorner;
	sf::Vector2f topRightCorner;
	sf::Vector2f bottomRightCorner;
	sf::Vector2f bottomLeftCorner;
};

corners calculateCornersPos(sf::RectangleShape object)
{
	sf::FloatRect spriteBounds = object.getLocalBounds();

	corners corners;
	corners.topLeftCorner = object.getTransform().transformPoint(sf::Vector2f(spriteBounds.left, spriteBounds.top));
	corners.topRightCorner = object.getTransform().transformPoint(sf::Vector2f(spriteBounds.left + spriteBounds.width, spriteBounds.top));
	corners.bottomRightCorner = object.getTransform().transformPoint(sf::Vector2f(spriteBounds.left + spriteBounds.width, spriteBounds.top + spriteBounds.height));
	corners.bottomLeftCorner = object.getTransform().transformPoint(sf::Vector2f(spriteBounds.left, spriteBounds.top + spriteBounds.height));

	return corners;
}

sf::VertexArray* getCollisionArea(corners corners)
{
	sf::Vertex points[5] = { corners.topLeftCorner, corners.topRightCorner, corners.bottomRightCorner, corners.bottomLeftCorner, corners.topLeftCorner };
	sf::VertexArray* collisionArea = new sf::VertexArray(sf::LineStrip, 5);

	for (int i = 0; i < 5; i++)
	{
		(*collisionArea)[i].position = points[i].position;
	}

	return collisionArea;
}

// calculate edges
void SAT::calculateEdges(sf::VertexArray* obj1, sf::VertexArray* obj2)
{
	/// 0 - topLeftCorner; 1 - topRightCorner; 2 - bottomRightCorner; 3 - bottomLeftCorner
	vectorABobj1 = sf::Vector2f((*obj1)[1].position.x - (*obj1)[0].position.x, (*obj1)[1].position.y - (*obj1)[0].position.y);
	vectorBCobj1 = sf::Vector2f((*obj1)[2].position.x - (*obj1)[1].position.x, (*obj1)[2].position.y - (*obj1)[1].position.y);
	vectorABobj2 = sf::Vector2f((*obj2)[1].position.x - (*obj2)[0].position.x, (*obj2)[1].position.y - (*obj2)[0].position.y);
	vectorBCobj2 = sf::Vector2f((*obj2)[2].position.x - (*obj2)[1].position.x, (*obj2)[2].position.y - (*obj2)[1].position.y);
}

void SAT::setNormalVector(sf::Vector2f& normVector, sf::Vector2f& vector)
{
	normVector = sf::Vector2f(-vector.y, vector.x);
}

void SAT::setProjectionVertex(float* projectionVertexObj, sf::Vector2f& normVector, sf::VertexArray* obj)
{
	/// 0 - topLeftCorner; 1 - topRightCorner; 2 - bottomRightCorner; 3 - bottomLeftCorner
	for (int i = 0; i < 4; i++)
	{
		sf::Vector2f pos = (*obj)[i].position;
		projectionVertexObj[i] = (normVector.x * pos.x + normVector.y * pos.y) / sqrt(pow(normVector.x, 2.0) + pow(normVector.y, 2.0));
	}
}

void SAT::searchMinMax(float& objMin, float& objMax, float* projectionVertexObj)
{
	objMin = projectionVertexObj[0];
	objMax = projectionVertexObj[0];
	for (int i = 1; i < 4; i++)
	{
		if (objMin > projectionVertexObj[i]) objMin = projectionVertexObj[i];
		if (objMax < projectionVertexObj[i]) objMax = projectionVertexObj[i];
	}
}

void SAT::normalize(sf::Vector2f& vect)
{
	if (vect.x != 0) vect.x /= vect.x;
	if (vect.y != 0) vect.y /= vect.y;
}

bool SAT::collisionSAT(sf::RectangleShape& obj1, sf::RectangleShape& obj2)
{
	bool collided = true;
	int counter = 1;

	corners obj1Corners = calculateCornersPos(obj1);
	corners obj2Corners = calculateCornersPos(obj2);

	/// vertexes of object 1 are: a - topleftcorner, b - toprightcorner, c - bottomrightcorner, d - bottomleftcorner (clockwise)
	/// vertexes of object 2 are: e, f, g, h (clockwise)
	calculateEdges(getCollisionArea(obj1Corners), getCollisionArea(obj2Corners));

	setNormalVector(normVectorABobj1, getVectorABobj1());
	setNormalVector(normVectorBCobj1, getVectorBCobj1());
	setNormalVector(normVectorABobj2, getVectorABobj2());
	setNormalVector(normVectorBCobj2, getVectorBCobj2());

	sf::Vector2f normVector;

	while (collided == true && counter <= 4)
	{
		/// for normvectorabplayer
		if (counter == 1) normVector = normVectorABobj1;
		/// for normvectorbcplayer
		else if (counter == 2) normVector = normVectorBCobj1;
		/// for normvectoreftraffic
		else if (counter == 3) normVector = normVectorABobj2;
		/// for normvectorghtraffic
		else if (counter == 4) normVector = normVectorBCobj2;

		setProjectionVertex(projectionVertexObj1, normVector, getCollisionArea(obj1Corners));
		searchMinMax(obj1Min, obj1Max, projectionVertexObj1);

		setProjectionVertex(projectionVertexObj2, normVector, getCollisionArea(obj2Corners));
		searchMinMax(obj2Min, obj2Max, projectionVertexObj2);

		/// negation of collision
		if (!(((obj1Min < obj2Max) && (obj1Min > obj2Min)) || ((obj2Min < obj1Max) && (obj2Min > obj1Min))))
		{
			collided = false;
		}
		calculateMTV(counter);
		counter++;
	}
	return collided;
}

std::vector<sf::Vector2f> SAT::getEdges()
{
	std::vector<sf::Vector2f> temp;

	temp.push_back(vectorABobj1);
	temp.push_back(vectorBCobj1);
	temp.push_back(vectorABobj2);
	temp.push_back(vectorBCobj2);

	return temp;
}

void SAT::calculateMTV(int counter)
{
	if (counter == 1)
	{
		distance = abs(obj1Max - obj2Min);
		oppositeCounter = counter;
	}
	else
	{
		if (distance > abs(obj1Max - obj2Min))
		{
			distance = abs(obj1Max - obj2Min);
			oppositeCounter = counter;
		}
	}
	if (distance > abs(obj2Max - obj1Min))
	{
		distance = abs(obj2Max - obj1Min);
		oppositeCounter = counter;
	}
}