inherit ROOM;
 
void create()
{
        set("short", "С·");
        set("long",@LONG
����һ��С��������������Զ�����졣С��������ֲ��һЩ�һ�����
��ֻһƳ�ͷ��֣���Щ�һ�ȫ�ǰ�ɫ�ġ�
LONG );
        set("exits", ([
            "south" : __DIR__"road2",
            "north" : __DIR__"mudi",
        ]));
        set("outdoors", "taohua");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
