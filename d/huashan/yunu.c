// yunu.c

inherit ROOM;

void create()
{
        set("short", "��Ů��");
	set("long", @LONG
�����ǻ�ɽ���з壬��Ů�塣��˵����ʱ��ʿ��ʷ�ƴ����������
�������¹�Ů��Ū��İ�Ľ�������˹�͢�������ʷ�������ӣ��ʳ���
Ů�塣���������Ϊƽ�������������ķ���վ��������Ϻպ������Ļ�ɽ
���ɾ��ڴ˴�����������СС������Ǿ�����Ů���ˡ�����ϡϡ������
ʮ���䷿�ӣ��ǻ�ɽ�ɵĵط��������ο���ñ�������ȥ��
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
            "westdown"  : __DIR__"zhenyue",
            "west"      : __DIR__"yunuci",
            "north"     : __DIR__"square",
            "southdown" : __DIR__"yunupath1",
            "northeast" : __DIR__"xiaolu1",
       ]));
       set("objects", ([
            __DIR__"npc/yue-lingshan" : 1,
       ]));

//        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
