// baishulin4.c ������
// By Lgg,1998.10

#undef DEBUG_COUNT
inherit ROOM;
int do_kan(string arg);

void create()
{
        set("short", "������");
        set("long", @LONG
���������ֵı�Ե���������Ķ��ˡ�����İ���Ҳϡ���˺ܶࡣ
�Ա���һ�Թ�ľ(frutex)��������ľ����ǰ�����������ˡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "west" : __DIR__"baishulin3",
                "southdown" : __DIR__"baishulin2",
        ]));
        set("no_clean_up", 0);
        set("count",1);
        set("item_desc", ([
        "frutex": "һ����в������ֵĹ�ľ�����м����źܶ�С�̡�\n"
        ]) );

        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_kan","kan");
}

int do_kan(string arg)
{
        object me=this_player();
        object weapon;
        object ob;

        if( !arg || arg != "frutex" ) {
                return notify_fail("��Ҫ��ʲô��\n");
        }

        if (!objectp(weapon = me->query_temp("weapon")))
                return notify_fail("���üһ���²��аɣ�\n");

        if (query("count")>0) {
        message_vision("$N�γ����У��ߵ���ľ�Ը�ǰһ���ҿ�������ǰһЩ�����Ĺ�ľ\n",me);
        message_vision("�����Ժ�$N��������������һ��ʲôС�ݣ�����˳�ְ���������\n", me);
        message_vision("û�뵽�ⶫ���������źô�һ�������\n",me);
        add("count",-1);
        ob=new(__DIR__"obj/fuling");
        ob->move(me);
        }
        else {
        message_vision("$N�γ����У��ߵ���ľ�Ը�ǰһ���ҿ�������ǰһЩ�����Ĺ�ľ\n",me);
        message_vision("�����ˡ�$N�۵Ĺ�Ǻ��\n", me);
        }

        return 1;
}

void reset()
{//���������������Ͳ����� count �� BUG
        if( query("count") < 1 && random(10) < 3 )//������Ҫ��Щ��������Щ���أ���ûȷ�� :P
                 set("count",1);
#ifdef DEBUG_COUNT
        if( find_player("robin") )
                tell_object(find_player("robin"),"Start Reset: count="+query("count")+"\n");
#endif
        return ::reset();
}

