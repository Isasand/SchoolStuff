#pragma once


class Pyramid {
public:
	Pyramid(float X, float Y) { m_bredd = X; m_hojd = Y; };
	Pyramid() { m_bredd = 1; m_hojd = 1; };
	float x() const;
	float y() const;
	void setx(float x);
	void sety(float y);
	float area();
	float Volym();
	void change(float x, float y) ;

private:
	float m_bredd;
	float m_hojd;
};
