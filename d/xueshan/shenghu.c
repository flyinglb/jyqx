//      shenghu.c ʥ��
//      Designed by secret (����)
//      97/04/07

inherit ROOM;

void create()
{
        set("short","ʥ��");
        set("long",@LONG
��ǰ����������ʥ���������ĺ��浹Ӱ������Ͱ��ƣ�
����ˮ�������Ŀ�������Զ����̻Ի͵�ѩɽ��������
������Զ���Ǽ�������Ĵ�ѩɽ��������ߴ������ɽ��
�ഫɽ�������ɾ�ס��ѩɽ���ڻ���ѩˮ��������С�
LONG );
        set("resource/water",1);
        set("exits",([
                "south" : __DIR__"tulu3",
                "east"  : __DIR__"hubian1",
		"west"  : "/d/npc/m_weapon/liangunshi",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

