// kedian2.c

inherit ROOM;

void create()
{
        set("short", "�͵��¥");
        set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����Сľ����
���ٿ��������¶��ԣ������Ӷ��Ǻ����Ĵ������������Ŵ��ǿյģ�
��������ŵ����˹�ȥ��
LONG
        );
        set("sleep_room", "1");
        set("no_fight", "1");
        set("hotel",1);
        set("no_clean_up", 0);
        set("exits", ([
                "down" : __DIR__"kedian1",
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        if ( dir == "down" ) me->delete_temp("rent_paid");

        return ::valid_leave(me, dir);
}

