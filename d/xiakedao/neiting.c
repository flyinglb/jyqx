// neiting.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ��ʯ�����˶�˶���������ܵ����˻�ѣ�������������
ҫ��ʮ���������м���źܶ�ʯ����ʯ�ʣ��кܶ�Ľ���������ʯ��
�ڲ����书֮�࣬��������Ϣһ�ᡣ
LONG );
// �����ſڿ�����һ��С��(hole)��
        set("exits", ([
                "enter" : __DIR__"shihole1",
                "north" : __DIR__"xiuxis2",
                "east"  : __DIR__"shibi",
                "west"  : __DIR__"chashi",
        ]));

        set("objects", ([
                __DIR__"npc/shipotian" : 1,
                __DIR__"npc/daoseng": 1,
                __DIR__"npc/dizi": 2,
        ]));

        setup();
}

int do_enter(string arg)
{
        object me;
        mapping fam;

        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="hole" )
        {
                if( (fam = me->query("family")) && fam["family_name"] == "ؤ��")
                {
                        message("vision",
                                me->name() + "����ؤ�����ǹ���һ�������������˽�ȥ��\n",
                                environment(me), ({me}) );
                        me->move("/d/gaibang/undersld");
                        message("vision",
                                me->name() + "�Ӷ������˽�����\n", environment(me), ({me}) );
                        return 1;
                }
                else
                        return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
        }
}
