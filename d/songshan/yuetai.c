// Room: /d/songshan/yuetai.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "��̨");
	set("long", @LONG
�����Ƿ����µ���̨������̨������̫��ɽ�͸������ƣ��¶�
��˫����ƣ��м����硣���� "����" ������ѽڣ������Է�����
����������֮�У���������ɽ�ȣ�����ǵǷ�˾�֮һ�� "����
����" ��
LONG );
	set("exits", ([
		"east" : __DIR__"fawangsi",
	]));
	set("objects", ([
		__DIR__"npc/fei" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

