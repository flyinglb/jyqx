// Room: /d/shaolin/fanting1.c
// Date: YZC 96/01/19

inherit ROOM;

string* names = ({
	__DIR__"obj/mizhi-tianou",
	__DIR__"obj/jiaxin-biji",
	__DIR__"obj/basi-shanyao",
	__DIR__"obj/furong-huagu",
});

void create()
{
	set("short", "ի��");
	set("long", @LONG
�����������ȫ����ɮ��ի�ĵط���ի���������������
ǧ��ͬʱ���š��Ӷ�����һ���Ű����˳����Ĳ����ͳ��ʣ���λ
С����������æµ�Ų�����ի�����ϰ��˼��趹�������������
�Լ���Ѽ����ζ��ʳ�������Ǹ�������
LONG );
	set("exits", ([
		"south" : __DIR__"fanting",
		"north" : __DIR__"chufang",
	]));
	set("objects",([
        	__DIR__"obj/qingshui-hulu" : 1,
		names[random(sizeof(names))]: 1,
		names[random(sizeof(names))]: 1,		
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

