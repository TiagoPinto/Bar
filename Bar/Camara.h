class CVector3 {
public:
	float x, y, z;

	// A default constructor
	CVector3();

	// This is our constructor that allows us to initialize our data upon creating an instance
	CVector3(float X, float Y, float Z);

	// Here we overload the + operator so we can add vectors together 
	CVector3 operator+(CVector3 vVector);

	// Here we overload the - operator so we can subtract vectors 
	CVector3 operator-(CVector3 vVector);
	
	// Here we overload the * operator so we can multiply by scalars
	CVector3 operator*(float num);

	// Here we overload the / operator so we can divide by a scalar
	CVector3 operator/(float num);		
};


// This is our camera class
class CCamera {

public:
	CVector3 m_vPosition;						// The camera's position
	CVector3 m_vView;							// The camera's View
	CVector3 m_vUpVector;						// The camera's UpVector
	
	// Our camera constructor
	CCamera();

	// This changes the position, view, and up vector of the camera. (Used for initialization)
	void PositionCamera(float positionX, float positionY, float positionZ,
			 		    float viewX,     float viewY,     float viewZ,
						float upVectorX, float upVectorY, float upVectorZ);


	// If we don't want use the keyboard to look around, this will use the mouse.
	// This type of viewing is used in most first person games.  
	void SetViewByMouse(float angleY, float angleZ);


	// This rotates the camera's view around the position using axis-angle rotation
	void RotateView(float angle, float x, float y, float z);

	// This will move the camera forward or backward depending on the speed
	void MoveCamera(float speed);

	void CCamera::MoveCameraSides(float speed);
};
