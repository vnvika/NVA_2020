#include "stdafx.h"

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		//��������� ������
		ERROR_ENTRY(0, "SYSTEM ������������ ��� ������"),
		ERROR_ENTRY(1, "SYSTEM ��������� ����"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40),
		ERROR_ENTRY_NODEF10(50), ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),



		ERROR_ENTRY(100, "SYSTEM �������� -in ������ ���� �����"),
		ERROR_ENTRY(101, "SYSTEM ��������� ����� �������� ���������"),
		ERROR_ENTRY(102, "SYSTEM ������ ��� �������� ����� � �������� �����(-in)"),
		ERROR_ENTRY(103, "SYSTEM ������ ��� �������� ����� ���������(-log)"),
		ERROR_ENTRY_NODEF(104), ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107), ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY_NODEF10(110), ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140),
		ERROR_ENTRY_NODEF10(150), ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),



		//����������� ������
		ERROR_ENTRY(200, "ERROR 200 ������������ ������ � �������� �����(-in)"),
		ERROR_ENTRY(201, "ERROR 201 ����������� ������������������ ��������"),
		ERROR_ENTRY(202, "ERROR 202 �������� ������ ������� ������"),
		ERROR_ENTRY(203, "ERROR 203 �������� ������ ������� ���������������"),
		ERROR_ENTRY(301, "ERROR 301 ����������� ����� ����� main"),
		ERROR_ENTRY(302, "ERROR 302 ��������� ����� ����� main"),
		ERROR_ENTRY_NODEF(204), ERROR_ENTRY_NODEF(205), ERROR_ENTRY_NODEF(206), ERROR_ENTRY_NODEF(207), ERROR_ENTRY_NODEF(208), ERROR_ENTRY_NODEF(209),
		ERROR_ENTRY_NODEF10(210), ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240),
		ERROR_ENTRY_NODEF10(250), ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),
		

		//������������� ������
		ERROR_ENTRY(300, "ERROR 300 ������������� �� ��������"),
		ERROR_ENTRY(303, "ERROR 303 �� ������ ��� �������������� ��� ����������"),
		ERROR_ENTRY(304, "ERROR 304 ����������� �������� ����� ��� ����������"),
		ERROR_ENTRY(305, "ERROR 305 ������� ��������������� ��������������"),
		ERROR_ENTRY(306, "ERROR 306 ��������� ������������ ���������� ���������� �������"),
		ERROR_ENTRY(307, "ERROR 307 ������� ����� ���������� � ������ �������"),
		ERROR_ENTRY(308, "ERROR 308 ���-�� ��������� �������� � ������������ ���������� �� ���������"),
		ERROR_ENTRY(309, "ERROR 309 ������������ ����� ������������ ����������"),
		ERROR_ENTRY(310, "ERROR 310 ������������� ������� ���������� �������� �����������"),
		ERROR_ENTRY(311, "ERROR 311 ��������� ������ \'\"\'. ��������, �� ������ ��������� �������"),
		ERROR_ENTRY(312, "ERROR 312 �������� ������ ���������� ��������"),
		ERROR_ENTRY(313, "ERROR 313 ������������ ������������� �������"),
		ERROR_ENTRY(314, "ERROR 314 ���� ������ � ��������� �� ���������"),
		ERROR_ENTRY(315, "ERROR 315 ��� ������� � ������������� �������� �� ���������"),
		ERROR_ENTRY(316, "ERROR 316 ������������ ��������� ��������� ����� \'=\'"),
		ERROR_ENTRY(317, "ERROR 317 �� ������ ���� main"),
		ERROR_ENTRY_NODEF(318), ERROR_ENTRY_NODEF(319),
		ERROR_ENTRY_NODEF10(320),ERROR_ENTRY_NODEF10(330),ERROR_ENTRY_NODEF10(340),ERROR_ENTRY_NODEF10(350),
		ERROR_ENTRY_NODEF10(360),ERROR_ENTRY_NODEF10(370),ERROR_ENTRY_NODEF10(380),ERROR_ENTRY_NODEF10(390),
		ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),

		//�������������� ������
		ERROR_ENTRY(600, "ERROR 600 ������. �������� ��������� ���������"),
		ERROR_ENTRY(601, "ERROR 601 ������. �� ������ ������ ���������� �������"),
		ERROR_ENTRY(602, "ERROR 602 ������ � ���� �������"),
		ERROR_ENTRY(603, "ERROR 603 ������ � ���� ���������"),
		ERROR_ENTRY(604, "ERROR 604 ������ � ������ ���������� �������"),
		ERROR_ENTRY(605, "ERROR 605 ������ � ������ �������/���������"),
		ERROR_ENTRY(606, "ERROR 606 ������ � ������ ����������� ���������� �������"),
		ERROR_ENTRY(607, "ERROR 607 ������. �������� �������������� ��������"),
		ERROR_ENTRY(608, "ERROR 608 ������. �������� ���������. ��������� ������ ��������������/��������"),
		ERROR_ENTRY(609, "ERROR 609 ������ � �������������� ���������"),
		ERROR_ENTRY(610, "ERROR 610 ������. ������������ �������������� �����������"),
		ERROR_ENTRY_NODEF10(620), ERROR_ENTRY_NODEF10(630), ERROR_ENTRY_NODEF10(640), ERROR_ENTRY_NODEF10(650),
		ERROR_ENTRY_NODEF10(660), ERROR_ENTRY_NODEF10(670), ERROR_ENTRY_NODEF10(680), ERROR_ENTRY_NODEF10(690),
		ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
	};

	ERROR GetError(int id)
	{
		if (id < 0 || id > ERROR_MAX_ENTRY)
			return errors[0];
		else
			return errors[id];
	}

	ERROR GetError(int id, int line, int cells)
	{
		ERROR err = GetError(id);
		err.position.cells = cells;
		err.position.line = line;
		return err;
	}
};