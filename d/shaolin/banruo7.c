// Room: /d/shaolin/banruo7.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�������߲�");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬��
�ڿյ����ر��������������İڷ��ż��������ҷ��ڵĻƲ�
���ţ���λ�뷢���׵���ɮ�������������Ŀ�붨�������Ǳ���
ʮ���޺��������еĵط������پ����书�����ڴ������
LONG );
	set("exits", ([
		"south" : __DIR__"banruo6",
		"north" : __DIR__"banruo8",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/cheng-ling" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

