// Room: /d/shaolin/banruo5.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�������岿");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬��
�ڿյ����ر��������������İڷ��ż��������ҷ��ڵĻƲ�
���ţ���λ�뷢���׵���ɮ�������������Ŀ�붨�������Ǳ���
ʮ���޺��������еĵط������پ����书�����ڴ������һλС
ɳ����һ�ߴ���վ����
LONG );
	set("exits", ([
		"east" : __DIR__"wuchang1",
		"south" : __DIR__"banruo4",
		"north" : __DIR__"banruo6",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/xuan-nan" : 1,
		CLASS_D("shaolin") + "/cheng-zhi2" : 1,
		__DIR__"npc/xiao-nan" : 1
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

