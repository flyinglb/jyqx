// Room: /u/mei/room69.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
int do_zuan(string arg);
int do_climb(string arg);
void create()
{
        set("short", "����");
        set("long", @LONG
����һ��������������Բ�أ��ر߳����˴��̵����٣������ƺ�����
����ȥ���ص���һ����(hole)��
LONG
        );
        set("item_desc", ([
        "hole" : "�ƺ�������(zuan)��ȥ��\n",

        ]));
    set("objects", ([
               "/d/gaochang/obj/feituoarmor": 1,
]));
        setup();
}

void init()
{
        add_action("do_zuan", "zuan");
        add_action("do_climb", "climb");
//      call_out("add_per",10,this_player());
}
/*
void add_per(object me)
{
    if (!me || environment(me)!=this_object()) return;
    if (userp(me) && time()-(int)me->query_temp("per_time")>600 && (int)me->query("per")<30 && !me->query_temp("armor/cloth") ){
       tell_object(me,MAG+"��ͻȻ����������һ��Ư������Ӱ����Ц��Ц����Ͻ������Լ�һ�£���...�ò������ΰɣ�"+NOR);
       me->add("per",1);
    }
    me->set_temp("per_time",time());
}
*/

int do_zuan(string arg)
{
        object me;
        me = this_player();
        if (!arg || arg !="hole"){
            write("��Ҫ��ʲô��\n");
                 return 1;
            }
            {
            message("vision", me->name() + "����һ�²�֪��ʲô�ط����ȥ�ˡ�\n",
                    environment(me), ({me}) );
                     write("��Ȼһ�����������������һ�����ģ����һ�������ã�\n");
            me->set("qi",-1);
            me->unconcious();
            me->move(__DIR__"room43");
            message("vision", me->name() + "���ٲ������˳�����\n",
                    environment(me), ({me}) );
            return 1;
            }

}
int do_climb(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg!="��") return notify_fail("��Ҫ��ʲô��\n");
            message("vision", me->name() + "˳����������ȥ��\n",
                    environment(me), ({me}) );
        me->move(__DIR__"room40");
            message_vision("$Nˮ���ܵ�����������\n", me);
        return 1;
}

