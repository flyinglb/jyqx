// hollow.c

inherit ROOM;

void create()
{
        set("short", "ѩ��");
        set("long", @LONG
���Ǵ�ѩɽ���µ�һ��ѩ�ӡ������˸������ ����ؤ���
���ռ�����ͭ�����ȡ��ӱ�����һ��С��(dong)��
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "up"   : __DIR__"sroad3",
        ]));
        set("item_desc", ([
            "dong"   : "һ�������İ��Ķ�Ѩ��\n",
        ]));
        set("objects",([
                __DIR__"npc/zhizhu" : 1,
        ]));
        setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
        object me;
        mapping fam;

        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="dong" )
        {
           if( (fam = me->query("family")) && fam["family_name"] == "ؤ��")
           {
               message("vision",
                        me->name() + "����ؤ�����ǹ���һ�������������˽�ȥ��\n",
                        environment(me), ({me}) );
               me->move("/d/gaibang/underxs");
               message("vision",
                        me->name() + "�Ӷ������˽�����\n",
                        environment(me), ({me}) );
                        return 1;
           }
           else  return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
       }
}
