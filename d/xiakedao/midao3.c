// midao3.c �ܵ�


inherit ROOM;

void create()
{
        set("short", "����ͨ��");
        set("long", @LONG
����һ���ܳ�������ͨ����Ҳ��þ�û�������ˣ��ܵ��г���
��һ�ֳ�ʪ����ζ����Լ���Ըо��������Ǳ����ʯ�ڣ���ʲôҲ
��������ֻ���Կ�������ǰ����
LONG );
        set("exits", ([
               "north" : __DIR__"midao2",
               "west" : __DIR__"midao4",
               "east" : __FILE__,
               "south" : __FILE__,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
