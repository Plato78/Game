#include <SFML/Graphics.hpp>
#include"Nigga.h"
using namespace sf;

int main()
{

	srand(time(nullptr));

	using namespace sf;
	const float length = 800;
	const float width = 600;
	const float length_bat = 20;
	const float width_bat = 80;
	const float ballradius = 10;
	const float otstup = 50;
	const float ball_posx = length / 2 - 10;
	const float ball_posy = width / 2 - 10;
	const Color batcolor1(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
	const Color batcolor2(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
	const Vector2f batsize(length_bat, width_bat);
	const Vector2f ballsize(ball_posx, ball_posy);
	const float batSpeed = 5.f;
	const float LeftScore_posx = 88.f;
	const float LeftScore_posy = 50.f;
	const float RightScore_posx = 680.f;
	const float RightScore_posy = 50.f;

	// ������, �������, ����������, �������� ������� ����� ����������

	RenderWindow window(VideoMode(length, width), "SFML Works!");
	window.setFramerateLimit(60);
	Texture textur;
	textur.loadFromFile("futbl.jpg");
	Texture textur1;
	textur1.loadFromFile("setka.png");
	//�����
	CircleShape ball(ballradius);
	initball(ball,ballColor,ballsize);
	//ball.setPosition(ball_posx, ball_posy);
	//ball.setFillColor(Color::White);
	//ball.setOutlineColor(Color::Black);
	ball.setOutlineThickness(2);
	const float ball_dx = 2;
	const float ball_dy = 2;
	float arr_speed[]{ -5.f,5.f };
	int index = rand() % 2;
	float ball_speedx = arr_speed[index];
	index = rand() % 2;
	float ball_speedy = arr_speed[index];
	/*
	//���� ����������
	/*RectangleShape pl(Vector2f(800, 600));
	pl.setTexture(&textur);*/
	//����� �������
	RectangleShape leftbat(batsize);
	/*leftbat.setPosition(otstup, width / 2 - 40);
	leftbat.setFillColor(batcolor1);*/
	initBat(leftbat, batcolor1, leftBatStartPos);
	//������ ������� 
	RectangleShape rightbat(batsize);
	initBat(rightbat, batcolor2, rightBatStartPos);
	/*rightbat.setPosition(length - otstup - 20, width / 2 - 40);
	rightbat.setFillColor(batcolor2);*/
	float leftB�tSpeedY = 0.f;
	float rightB�tSpeedY = 0.f;



	//����
	int LeftPlayerScore = 0;
	int RightPlayerScore = 0;
	Font font;
	font.loadFromFile("ds-digib.ttf");
	Text LeftPlayerScoreText;
	LeftPlayerScoreText.setString(std::to_string(LeftPlayerScore));
	LeftPlayerScoreText.setFont(font);
	LeftPlayerScoreText.setCharacterSize(64);
	LeftPlayerScoreText.setPosition(LeftScore_posx, LeftScore_posy);
	LeftPlayerScoreText.setFillColor(Color::White);
	Text RightPlayerScoreText;
	RightPlayerScoreText.setString(std::to_string(RightPlayerScore));
	RightPlayerScoreText.setFont(font);
	RightPlayerScoreText.setCharacterSize(64);
	RightPlayerScoreText.setPosition(RightScore_posx, RightScore_posy);
	RightPlayerScoreText.setFillColor(Color::White);
	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		//�������� ������� ������
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			leftB�tSpeedY = -batSpeed;
			if (leftbat.getPosition().y <= 0)
			{
				leftbat.setPosition(otstup, 0);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			leftB�tSpeedY = batSpeed;
			if (leftbat.getPosition().y >= (width - 80))
			{
				leftbat.setPosition(otstup, width - 80);
			}

		}
		leftbat.move(0, leftB�tSpeedY);
		leftB�tSpeedY = 0.f;
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			rightB�tSpeedY = -batSpeed;
			if (rightbat.getPosition().y <= 0)
			{
				rightbat.setPosition(length - otstup - 20, 0);
			}

		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			rightB�tSpeedY = batSpeed;
			if (rightbat.getPosition().y >= (width - 80))
			{
				rightbat.setPosition(length - otstup - 20, width - 80);
			}
		}
		rightbat.move(0, rightB�tSpeedY);
		rightB�tSpeedY = 0.f;

		// �������� ������
		ball.move(ball_speedx, ball_speedy);
		if (ball.getPosition().x <= 0) {

			ball_speedx = -ball_speedx;
			RightPlayerScore++;
			RightPlayerScoreText.setString(std::to_string(RightPlayerScore));
		}

		if (ball.getPosition().x >= (length - 2 * ballradius)) {

			ball_speedx = -ball_speedx;
			LeftPlayerScore++;
			LeftPlayerScoreText.setString(std::to_string(LeftPlayerScore));

		}

		if (ball.getPosition().y <= 0 || ball.getPosition().y >= (width - 2 * ballradius))
		{
			ball_speedy = -ball_speedy;
		}
		float midLeftX = ball.getPosition().x;
		float midLeftY = ball.getPosition().y + ballradius;
		float midRightX = ball.getPosition().x + 2 * ballradius;
		float midRightY = ball.getPosition().y + ballradius;
		float midUpX = ball.getPosition().x + ballradius;
		float midUpY = ball.getPosition().y;
		float midDownX = ball.getPosition().x + ballradius;
		float midDownY = ball.getPosition().y + 2 * ballradius;
		//����� �������
		if ((leftbat.getPosition().x <= midLeftX) && (midLeftX <= (leftbat.getPosition().x + length_bat)) && (leftbat.getPosition().y <= midLeftY) && (midLeftY <= leftbat.getPosition().y + width_bat))
		{
			ball_speedx = -ball_speedx;

		}
		if ((leftbat.getPosition().x <= midRightX) && (midRightX <= (leftbat.getPosition().x + length_bat)) && (leftbat.getPosition().y <= midRightY) && (midRightY <= leftbat.getPosition().y + width_bat))
		{
			ball_speedx = -ball_speedx;
		}
		if ((leftbat.getPosition().x <= midUpX) && (midUpX <= (leftbat.getPosition().x + length_bat)) && (leftbat.getPosition().y <= midUpY) && (midUpY <= leftbat.getPosition().y + width_bat))
		{
			if (ball_speedy < 0) {
				ball_speedy = -ball_speedy;
			}
		}
		if ((leftbat.getPosition().x <= midDownX) && (midDownX <= (leftbat.getPosition().x + length_bat)) && (leftbat.getPosition().y >= midDownY) && (midDownY > leftbat.getPosition().y - 1))
		{
			if (ball_speedy > 0) {
				ball_speedy = -ball_speedy;
			}
		}
		//������ �������
		if ((rightbat.getPosition().x <= midLeftX) && (midLeftX <= (rightbat.getPosition().x + length_bat)) && (rightbat.getPosition().y <= midLeftY) && (midLeftY <= rightbat.getPosition().y + width_bat))
		{
			ball_speedx = -ball_speedx;

		}
		if ((rightbat.getPosition().x <= midRightX) && (midRightX <= (rightbat.getPosition().x + length_bat)) && (rightbat.getPosition().y <= midRightY) && (midRightY <= rightbat.getPosition().y + width_bat))
		{
			ball_speedx = -ball_speedx;
		}
		if ((rightbat.getPosition().x <= midUpX) && (midUpX <= (rightbat.getPosition().x + length_bat)) && (rightbat.getPosition().y <= midUpY) && (midUpY <= rightbat.getPosition().y + width_bat))
		{
			if (ball_speedy < 0) {
				ball_speedy = -ball_speedy;
			}
		}
		if ((rightbat.getPosition().x <= midDownX) && (midDownX <= (rightbat.getPosition().x + length_bat)) && (rightbat.getPosition().y <= midDownY) && (midDownY <= rightbat.getPosition().y + width_bat))
		{
			if (ball_speedy > 0) {
				ball_speedy = -ball_speedy;
			}
		}




		//��������� ��������
		window.clear(Color::Black);
		//window.draw(pl);
		window.draw(leftbat);
		window.draw(rightbat);
		window.draw(ball);
		window.draw(LeftPlayerScoreText);
		window.draw(RightPlayerScoreText);
		window.display();
	}

	return 0;
}
