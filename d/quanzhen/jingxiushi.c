// jingxiushi.c ������
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ȫ��̵��Ӿ��޲������ķ��䣬�����С������ʰ�ĸ�
�ɾ��������ζ��ڷŵ��������룬����һ�����������
LONG
        );
        set("exits", ([
                "east" : __DIR__"houshan",
                "south" : __DIR__"diziju",
                "west" : __DIR__"houtang3",
        ]));
        set("objects", ([
                __DIR__"npc/liu" : 1,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        mapping fam;

        if (dir == "east" )
        {
                if(!(fam = me->query("family")) || fam["family_name"]!="ȫ���")
                {
                        if(present("liu chuxuan", environment(me)) && living(present("liu chuxuan", environment(me))))
                        {
                                return notify_fail(
"����һ������ס����������Ǳ�����ʦ����֮�أ�" + RANK_D->query_respect(me) + "��
ֹ����\n");
                        }
                        else
                                return ::valid_leave(me, dir);
                }
                else
                        return ::valid_leave(me, dir);
        }
        else
                return ::valid_leave(me, dir);

}
