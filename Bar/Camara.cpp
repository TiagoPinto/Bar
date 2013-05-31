#include <math.h>
#include "Camara.h"


/////	This returns a perpendicular vector from 2 given vectors by taking the cross product.											
CVector3 Cross(CVector3 vVector1, CVector3 vVector2) {
	CVector3 vNormal;									// The vector to hold the cross product

	// If we are given 2 vectors (the view and up vector) then we have a plane define.  
	// The cross product finds a vector that is perpendicular to that plane, 
	// which means it's point straight out of the plane at a 90 degree angle.
	// The equation for the cross product is simple, but difficult at first to memorize:
	
	// The X value for the vector is:  (V1.y * V2.z) - (V1.z * V2.y)													// Get the X value
	vNormal.x = ((vVector1.y * vVector2.z) - (vVector1.z * vVector2.y));
														
	// The Y value for the vector is:  (V1.z * V2.x) - (V1.x * V2.z)
	vNormal.y = ((vVector1.z * vVector2.x) - (vVector1.x * vVector2.z));
														
	// The Z value for the vector is:  (V1.x * V2.y) - (V1.y * V2.x)
	vNormal.z = ((vVector1.x * vVector2.y) - (vVector1.y * vVector2.x));

	// *IMPORTANT* This is not communitive. You can not change the order or this or
	// else it won't work correctly.  It has to be exactly like that.  Just remember,
	// If you are trying to find the X, you don't use the X value of the 2 vectors, and
	// it's the same for the Y and Z.  You notice you use the other 2, but never that axis.
	// If you look at the camera rotation tutorial, you will notice it's the same for rotations.

	// So why do I need the cross product to do a first person view?  Well, we need
	// to find the axis that our view has to rotate around.  Rotating the camera left
	// and right is simple, the axis is always (0, 1, 0).  Rotating around the camera
	// up and down is different because we are constantly going in and out of axises.
	// We need to find the axis that our camera is on, and that is why we use the cross
	// product.  By taking the cross product between our view vector and up vector,
	// we get a perpendicular vector to those 2 vectors, which is our desired axis.
	// Pick up a linear algebra book if you don't already have one, you'll need it.

	// Return the cross product
	return vNormal;										 
}

/////	This returns the magnitude of a vector
float Magnitude(CVector3 vNormal) {
	// This will give us the magnitude or "Norm" as some say of, our normal.
	// The magnitude has to do with the length of the vector.  We use this
	// information to normalize a vector, which gives it a length of 1.
	// Here is the equation:  magnitude = sqrt(V.x^2 + V.y^2 + V.z^2)   Where V is the vector

	return (float)sqrt( (vNormal.x * vNormal.x) + 
						(vNormal.y * vNormal.y) + 
						(vNormal.z * vNormal.z) );
}

/////	This returns a normalize vector (A vector exactly of length 1)
CVector3 Normalize(CVector3 vVector) {
	// What's this function for you might ask?  Well, since we are using the cross
	// product formula, we need to make sure our view vector is normalized.  
	// For a vector to be normalized, it means that it has a length of 1.
	// For instance, a vector (2, 0, 0) would be (1, 0, 0) once normalized.
	// Most equations work well with normalized vectors.  If in doubt, normalize.

	// Get the magnitude of our normal
	float magnitude = Magnitude(vVector);				

	// Now that we have the magnitude, we can divide our vector by that magnitude.
	// That will make our vector a total length of 1.  
	// This makes it easier to work with too.
	vVector = vVector / magnitude;		
	
	// Finally, return our normalized vector
	return vVector;										
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// A default constructor
CVector3::CVector3() {}

// This is our constructor that allows us to initialize our data upon creating an instance
CVector3::CVector3(float X, float Y, float Z)  {
	x = X; y = Y; z = Z;
}

// Here we overload the + operator so we can add vectors together 
CVector3 CVector3::operator+(CVector3 vVector) {
	// Return the added vectors result.
	return CVector3(vVector.x + x, vVector.y + y, vVector.z + z);
}

// Here we overload the - operator so we can subtract vectors 
CVector3 CVector3::operator-(CVector3 vVector) {
	// Return the subtracted vectors result
	return CVector3(x - vVector.x, y - vVector.y, z - vVector.z);
}
	
// Here we overload the * operator so we can multiply by scalars
CVector3 CVector3::operator*(float num) {
	// Return the scaled vector
	return CVector3(x * num, y * num, z * num);
}

// Here we overload the / operator so we can divide by a scalar
CVector3 CVector3::operator/(float num) {
	// Return the scale vector
	return CVector3(x / num, y / num, z / num);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

/////	This is the class constructor
CCamera::CCamera()
{
	CVector3 vZero = CVector3(0.0, 0.0, 5.0);		// Init a vVector to 0 0 0 for our position
	CVector3 vView = CVector3(0.0, 0.0, 0.0);		// Init a starting view vVector (looking up and out the screen) 
	CVector3 vUp   = CVector3(0.0, 1.0, 0.0);		// Init a standard up vVector (Rarely ever changes)

	m_vPosition	= vZero;							// Init the position to zero
	m_vView		= vView;							// Init the view to a std starting view
	m_vUpVector	= vUp;								// Init the UpVector
}

void CCamera::SetViewByMouse(float angleY, float angleZ){
	//float angleY = 0.0f;							// This is the direction for looking up or down
	//float angleZ = 0.0f;							// This will be the value we need to rotate around the Y axis (Left and Right)
	static float currentRotX = 0.0f;
	
	static float lastRotX = 0.0f; 
 	lastRotX = currentRotX; // We store off the currentRotX and will use it in when the angle is capped
	
	// Here we keep track of the current rotation (for up and down) so that
	// we can restrict the camera from doing a full 360 loop.
	currentRotX += angleZ;
 
	// If the current rotation (in radians) is greater than 1.0, we want to cap it.
	if(currentRotX > 1.5f){
		
		currentRotX = 1.5f;
		
		// Rotate by remaining angle if there is any
		if(lastRotX != 1.5f){
			// To find the axis we need to rotate around for up and down
			// movements, we need to get a perpendicular vector from the
			// camera's view vector and up vector.  This will be the axis.
			// Before using the axis, it's a good idea to normalize it first.
			CVector3 vAxis = Cross(m_vView - m_vPosition, m_vUpVector);
			vAxis = Normalize(vAxis);
				
			// rotate the camera by the remaining angle (1.0f - lastRotX)
			RotateView( 1.5f - lastRotX, vAxis.x, vAxis.y, vAxis.z);
		}
	}
	// Check if the rotation is below -1.0, if so we want to make sure it doesn't continue
	else if(currentRotX < -1.5f){
		currentRotX = -1.5f;
		
		// Rotate by the remaining angle if there is any
		if(lastRotX != -1.5f){
			// To find the axis we need to rotate around for up and down
			// movements, we need to get a perpendicular vector from the
			// camera's view vector and up vector.  This will be the axis.
			// Before using the axis, it's a good idea to normalize it first.
			CVector3 vAxis = Cross(m_vView - m_vPosition, m_vUpVector);
			vAxis = Normalize(vAxis);
			
			// rotate the camera by ( -1.0f - lastRotX)
			RotateView( -1.5f - lastRotX, vAxis.x, vAxis.y, vAxis.z);
		}
	}
	// Otherwise, we can rotate the view around our position
	else{
		// To find the axis we need to rotate around for up and down
		// movements, we need to get a perpendicular vector from the
		// camera's view vector and up vector.  This will be the axis.
		// Before using the axis, it's a good idea to normalize it first.
		CVector3 vAxis = Cross(m_vView - m_vPosition, m_vUpVector);
		vAxis = Normalize(vAxis);
	
		// Rotate around our perpendicular axis
		RotateView(angleZ, vAxis.x, vAxis.y, vAxis.z);
	}

	// Always rotate the camera around the y-axis
	RotateView(angleY, 0, 1, 0);
}

/////	This rotates the view around the position using an axis-angle rotation
void CCamera::RotateView(float angle, float x, float y, float z){
	CVector3 vNewView;

	// Get the view vector (The direction we are facing)
	CVector3 vView = m_vView - m_vPosition;		

	// Calculate the sine and cosine of the angle once
	float cosTheta = (float)cos(angle);
	float sinTheta = (float)sin(angle);

	// Find the new x position for the new rotated point
	vNewView.x  = (cosTheta + (1 - cosTheta) * x * x)		* vView.x;
	vNewView.x += ((1 - cosTheta) * x * y - z * sinTheta)	* vView.y;
	vNewView.x += ((1 - cosTheta) * x * z + y * sinTheta)	* vView.z;

	// Find the new y position for the new rotated point
	vNewView.y  = ((1 - cosTheta) * x * y + z * sinTheta)	* vView.x;
	vNewView.y += (cosTheta + (1 - cosTheta) * y * y)		* vView.y;
	vNewView.y += ((1 - cosTheta) * y * z - x * sinTheta)	* vView.z;

	// Find the new z position for the new rotated point
	vNewView.z  = ((1 - cosTheta) * x * z - y * sinTheta)	* vView.x;
	vNewView.z += ((1 - cosTheta) * y * z + x * sinTheta)	* vView.y;
	vNewView.z += (cosTheta + (1 - cosTheta) * z * z)		* vView.z;

	// Now we just add the newly rotated vector to our position to set
	// our new rotated view of our camera.
	m_vView = m_vPosition + vNewView;
}

/////	This will move the camera forward or backward depending on the speed
void CCamera::MoveCamera(float speed){
	// Get our view vector (The direciton we are facing)
	CVector3 vVector = m_vView - m_vPosition;
	
	m_vPosition.x += vVector.x * speed;		// Add our acceleration to our position's X
	m_vPosition.z += vVector.z * speed;		// Add our acceleration to our position's Z
	m_vView.x += vVector.x * speed;			// Add our acceleration to our view's X
	m_vView.z += vVector.z * speed;			// Add our acceleration to our view's Z
}

/////	This will move the camera left or right depending on the speed
void CCamera::MoveCameraSides(float speed){
	// Get our view vector (The direciton we are facing)
	CVector3 vVector = Cross(m_vUpVector, m_vView - m_vPosition);
	
	//CVector3 vVector = m_vView - m_vPosition;
	
	m_vPosition.x += vVector.x * speed;		// Add our acceleration to our position's X
	m_vPosition.z += vVector.z * speed;		// Add our acceleration to our position's Z
	m_vView.x += vVector.x * speed;			// Add our acceleration to our view's X
	m_vView.z += vVector.z * speed;			// Add our acceleration to our view's Z
}
