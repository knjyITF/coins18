#define FREEGLUT_STATIC

#include <cstdlib>
#include <cmath>
#include <vector>
#include <GL/glut.h>

class Vector3d {
public:
	double x, y, z;
	Vector3d() { x = y = z = 0; }
	Vector3d(double _x, double _y, double _z) { x = _x; y = _y; z = _z; }
	void set(double _x, double _y, double _z) { x = _x; y = _y; z = _z; }

	// ������1�ɐ��K������
	void normalize() {
		double len = length();
		x /= len; y /= len; z /= len;
	}

	// ������Ԃ�
	double length() { return sqrt(x * x + y * y + z * z); }

	// s�{����
	void scale(const double s) { x *= s; y *= s; z *= s; }

	// ���Z�̒�`
	Vector3d operator+(Vector3d v) { return Vector3d(x + v.x, y + v.y, z + v.z); }

	// ���Z�̒�`
	Vector3d operator-(Vector3d v) { return Vector3d(x - v.x, y - v.y, z - v.z); }

	// ���ς̒�`
	double operator*(Vector3d v) { return x * v.x + y * v.y + z * v.z; }

	// �O�ς̒�`
	Vector3d operator%(Vector3d v) { return Vector3d(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }

	// ������Z�̒�`
	Vector3d& operator=(const Vector3d& v) { x = v.x; y = v.y; z = v.z; return (*this); }

	// ���Z����̒�`
	Vector3d& operator+=(const Vector3d& v) { x += v.x; y += v.y; z += v.z; return (*this); }

	// ���Z����̒�`
	Vector3d& operator-=(const Vector3d& v) { x -= v.x; y -= v.y; z -= v.z; return (*this); }

	// �l���o�͂���
	void print() { printf("Vector3d(%f %f %f)\n", x, y, z); }
};
// �}�C�i�X�̕����̕t�����x�N�g����������悤�ɂ��邽�߂̒�` ��Fb=(-a); �̂悤�ɋL�q�ł���
Vector3d operator-(const Vector3d& v) { return(Vector3d(-v.x, -v.y, -v.z)); }

// �x�N�g���Ǝ����̐ς�������悤�ɂ��邽�߂̒�` ��F c=5*a+2*b; c=b*3; �̂悤�ɋL�q�ł���
Vector3d operator*(const double& k, const Vector3d& v) { return(Vector3d(k * v.x, k * v.y, k * v.z)); }
Vector3d operator*(const Vector3d& v, const double& k) { return(Vector3d(v.x * k, v.y * k, v.z * k)); }

// �x�N�g���������Ŋ��鑀���������悤�ɂ��邽�߂̒�` ��F c=a/2.3; �̂悤�ɋL�q�ł���
Vector3d operator/(const Vector3d& v, const double& k) { return(Vector3d(v.x / k, v.y / k, v.z / k)); }


// ����
class Sphere {
public:
	Vector3d center; // ���S���W
	double radius;   // ���a
	double cR, cG, cB;  // Red, Green, Blue �l 0.0�`1.0

	Sphere(double x, double y, double z, double r,
		double cr, double cg, double cb) {
		center.x = x;
		center.y = y;
		center.z = z;
		radius = r;
		cR = cr;
		cG = cg;
		cB = cb;
	}

	// �_p��ʂ�Av������Ray�Ƃ̌����𔻒肷��B
	// ��_�� p+tv �Ƃ��ĕ\����ꍇ�� t �̒l��Ԃ��B�����Ȃ��ꍇ��-1��Ԃ�
	double getIntersec(Vector3d& p, Vector3d& v) {
		// A*t^2 + B*t + C = 0 �̌`�ŕ\��
		double A = v.x * v.x + v.y * v.y + v.z * v.z;
		double B = 2.0 * (p.x * v.x - v.x * center.x +
			p.y * v.y - v.y * center.y +
			p.z * v.z - v.z * center.z);
		double C = p.x * p.x - 2 * p.x * center.x + center.x * center.x +
			p.y * p.y - 2 * p.y * center.y + center.y * center.y +
			p.z * p.z - 2 * p.z * center.z + center.z * center.z -
			radius * radius;
		double D = B * B - 4 * A * C; // ���ʎ�

		if (D >= 0) { // �����
			double t1 = (-B - sqrt(D)) / (2.0 * A);
			double t2 = (-B + sqrt(D)) / (2.0 * A);
			return t1 < t2 ? t1 : t2; // �������ق���t�̒l��Ԃ�
		}
		else { // �����Ȃ�
			return -1.0;
		}
	}
};


int halfWidth;    // �`��̈�̉���/2
int halfHeight;   // �`��̈�̏c��/2

// �e��萔
double d = 1000;  // ���_�Ɠ��e�ʂƂ̋���
double Kd = 0.8;  // �g�U���˒萔
double Ks = 0.8;  // ���ʔ��˒萔
double Iin = 1.0; // ���ˌ��̋��� 
double Ia = 0.2; // ����

Vector3d viewPosition(0, 0, 0); // ���_�ʒu
Vector3d lightDirection(-2, -4, -2); // ���ˌ��̐i�s����

// �����_�����O���鋅��
Sphere sphere(0.0, 0.0, -1500, // ���S���W
	150.0,           // ���a
	0.2, 0.9, 0.9);  // RGB�l


// �`����s��
void display(void) {

	glClear(GL_COLOR_BUFFER_BIT); // �`����e�̃N���A

	// �s�N�Z���P�ʂŕ`��F�����肷�郋�[�v����
	for (int y = (-halfHeight); y <= halfHeight; y++) {
		for (int x = (-halfWidth); x <= halfWidth; x++) {

			Vector3d ray(x - viewPosition.x, y - viewPosition.y, -d - viewPosition.z); // ���_����X�N���[����̃s�N�Z���֔�΂����C�̕���
			ray.normalize(); // ���C�̒����̐��K��

			// ���C���΂��ċ��Ƃ̌�_�����߂�
			double t = sphere.getIntersec(viewPosition, ray);

			if (t > 0) { // ��_������
				double Is = 0; // ���ʔ��ˌ�
				double Id = 0; // �g�U���ˌ�

				// �������� Is ����� Id �̒l���v�Z����!!!!!!!!!!!!!!!!!!!!!!!!!!
				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				Vector3d N(0, 0, 1); // �P�ʖ@���x�N�g��
				Id = Iin * kd * ((-lightDirection) * N);


				double I = Id + Is + Ia;
				double r = std::min(I * sphere.cR, 1.0); // 1.0 �𒴂��Ȃ��悤�ɂ���
				double g = std::min(I * sphere.cG, 1.0); // 1.0 �𒴂��Ȃ��悤�ɂ���
				double b = std::min(I * sphere.cB, 1.0); // 1.0 �𒴂��Ȃ��悤�ɂ���

				// �`��F�̐ݒ�
				glColor3d(r, g, b);

			}
			else { // ��_������

			 // �`��F�����ɂ���
				glColor3f(0.0f, 0.0f, 0.0f);
			}

			// (x, y) �̉�f��`��
			glBegin(GL_POINTS);
			glVertex2i(x, y);
			glEnd();
		}
	}
	glFlush();
}

void resize(int w, int h) {
	if (h < 1) return;
	glViewport(0, 0, w, h);
	halfWidth = w / 2;
	halfHeight = h / 2;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// �E�B���h�E���̍��W�n�ݒ�
	glOrtho(-halfWidth, halfWidth, -halfHeight, halfHeight, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27: exit(0);  /* ESC code */
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	lightDirection.normalize();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow(argv[0]);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}