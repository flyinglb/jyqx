// midao2.c �ܵ�


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
               "west" : __DIR__"midao1",
               "south" : __DIR__"midao3",
               "east" : __FILE__,
               "north" : __FILE__,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
