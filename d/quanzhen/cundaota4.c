// cundaota4.c �������
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

int do_dian(string arg);

void create()
{
        set("short", "�������");
        set("long", @LONG
�����Ǵ���������������ݵ�����͵��˾�ͷ��ǽ���Ͽ��ż�
������(window)��һ���������������һ�������ж�����ɫ�谵��
���ϰڷ���һ֧����(candle)��ȴû�е��š�
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"cundaota3",
        ]));
        set("objects", ([
                __DIR__"npc/zhangjing" : 1,
        ]));

        set("item_desc", ([
        "window": "�������Ʈ�����ƺ���һ���־Ϳ���ץסһƬ��\n",
        "candle": "һ֧��ͨ�������Ѿ����ֻʣһС���ˡ�\n"
        ]) );

        set("count",1);
        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_dian","dian");
}

int do_dian(string arg)
{
        object ob;
        object me=this_player();

        if (!arg || arg != "candle")
                return notify_fail("��Ҫ��ȼʲô��\n");

        if ( query("count")>0 &&
        present("zhangjing", environment(me)) &&
        living(present("zhangjing", environment(me))) ) {
                message_vision(HIG"$N����ǰȥ�����Ż�������ȼ�������ʱ��������ࡣ\n"NOR,this_player());
                message_vision("�ƾ�����̧��ͷ������մӳ�˼�лָ������Ƶģ�������\n",this_player());
                message_vision("ɫ�������𣬰����Ҷ��Ȿ���¾���Ȼ����ɫҲ�����ˡ�\n",this_player());
                message_vision("�ã���л��λ"+RANK_D->query_respect(me)+"�ˣ��������ⶫ������ҩʦ���͸���\n",this_player());
                message_vision("�ģ�Ҳ��֪����ʲô�ã������͸�������\n",this_player());
                add("count",-1);
                ob=new(__DIR__"obj/moyao");
                ob->move(me);
        }
        else {
                message_vision("$N����ǰȥ�����Ż�������ȼ�������ʱ��������ࡣ\n",this_player());
        }
        return 1;
}
