// Room: /d/shaolin/bydian.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���µ�");
	set("long", @LONG
���ǰ��µ������¹�����ʿ����ʿ�߾��������ϣ�����
��ƿ��ü��΢�����ǳЦ���·���˼伲��ȴ����ģ��־���
�������з��˺�ľ���㰸���㰸�Ϲ�Ʒ�뱸�����ʮ����ʢ��
LONG );
	set("exits", ([
		"west" : __DIR__"guangchang5",
	]));
        set("objects",([
                   __DIR__"npc/mu-ren" : 5
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

