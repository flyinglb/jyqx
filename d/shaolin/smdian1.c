// Room: /d/shaolin/smdian1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����Ƕ����������������Ŵ�Ħ��ʦ��������ʿ�Ļ�
���Լ�һЩ����Ԫ�ϵ��ֻ�������ɢ�ҵط���������ţ�ľ
��ȡ������˴��Ǳ��ɵ��Ӵ�������֮������λ����ɮ������
���붨���������ĵ�����������
LONG );
	set("exits", ([
		"west" : __DIR__"smdian",
	]));
	set("objects",([
		__DIR__"obj/muchui" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

