//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void do_close_hole();
void do_wugu_therapy_down(object me);

void create()
{
        set("short","�෿");
        set("long", @LONG
�����Ǻ�̫�����λ������õ����ң����г�����ҩζ�������ȴ���ڴ�
�ϣ������Բ�ʱ���Ѿ������ˡ���(bed)����Щ���ʵ�����������ҩ���˱Ƕ�
�������쳣�Ļ���������������ڵĴ���(window)�ƺ�����ź�԰��ĳһ
�ֻ��ݡ�
LONG );
        set("exits", ([
                "east" :  __DIR__"houhuayuan",
        ]));
        set("item_desc", ([

                "bed" : "һ��ľ����������Ȼ��������һ���ˣ����ƺ��������ƶ��ġ�\n",
                "window" : "�����ǲ��ǿ�������ȥ����\n",
        ]));
        set("objects", ([
                __DIR__"npc/binv" : 2,
        ]));
        set("snake_count",6-random(10));
        setup();
}
void init()
{
        add_action("do_move", "move");
        add_action("do_dig", "dig");
        add_action("do_use", "use");
        add_action("do_jump", "jump");
}
int do_move(string arg)
{
        object me;
        me = this_player();
        if (!arg || arg != "bed") return 0;
        if( present("wu gu", this_object()) ) {
                message_vision("��ö�$N���е������������ҷ��ڸ�ʲô������\n",me);
                return 1;
        }
        
        if( query("temp/snake_hole") ) {
                write("�ⴲ�Ѿ���Ų���ˡ�\n");
                return 1;
        }
        message_vision("$N����̧�𴲣�����һ�ߣ�������ǽ�ǵ�һ��С��(hole)��\n",me);
        add("item_desc", ([
                "hole" : "������׵�С�����ǲ��ǿ�����(dig)��ʲô����\n",
        ]));
        remove_call_out("do_close_hole");
        if( query("temp/snake_hole") < 1 )
        set("temp/snake_hole", 1);
        call_out("do_close_hole",10);
        return 1;
}

int do_dig(string arg)
{
        object me, ob1, ob2;
        me = this_player();
        if (!arg || arg != "hole") return 0;
        if( !query("temp/snake_hole") ) return notify_fail("��Ҫ��ʲô��\n");
        if( !present("lingzhilan", me) ) {
                message_vision("����ܳ�һ���ߣ���$N����ָ��ҧ��һ�ڣ��������˻�ȥ��\n",me);
                me->die();
        }
        else if (query("snake_count") < 1) {
                message_vision("$N���˰��죬����ʲôҲû�С�\n",me);
        } else {
                set("snake_count", 0);
                message("vision","����һǰһ���γ������ߣ�������֬������Ϣ�����˳�����\n",this_object());
                ob1 = new(__DIR__"obj/jinshe");
                ob2 = new(__DIR__"obj/yinshe");
                ob1->move(me);
                ob2->move(me);
        }
        return 1;
}

int do_use(string arg)
{
        object me, ob;
        me = this_player();
        if(!arg || (arg !="jinshe" && arg != "yinshe") ) {
                write("��Ҫ��ʹʲô��\n");
                return 1;
        }
        if( present("wu gu", this_object()) ) 
                message ("vision", "��úúõģ����뺦��ѽ��\n", me);
        else if(!ob = present(arg, me)) {
                        if(ob = present(arg,environment(me)) ) {
                                write("����û����������\n");
                                return 1;
                        }

        } else if (arg == "jinshe") {
                message_vision (HIY "��ɫѪ��"NOR"��$N���´�������������˴��ϵı����\n",me);
                ob->move(VOID_OB);
                destruct(ob);
                set("temp/jinshe", 1);
        } else {
                message_vision (HIW "��ɫѪ��"NOR"��$N���´�������������˴��ϵı����\n",me);
                ob->move(VOID_OB);
                destruct(ob);
                set("temp/yinshe", 1);
        }
        if( query("temp/jinshe") && query("temp/yinshe") ) {
                message("vision","����Ѫ�����������󣬵������ϻ��Ե����ͻȻһ������\n",this_object());
                set("temp/jinshe", 0);
                set("temp/yinshe", 0);
                set("in_wugu_therapy",1);
                call_out("do_wugu_therapy_down",20, me);
        }
        return 1;
}
int do_jump(string arg)
{
        object me;
        if (!arg || arg != "window") return 0;
        me = this_player();
        message_vision("$N�Ӵ������˳�ȥ��\n", me);
        me->move(__DIR__"houhuayuan1");
        message_vision("$N����÷��Ĵ������˹�����\n", me);
        return 1;
}

void do_close_hole()
{
        if( query("in_wugu_therapy") ) return;
        message("vision","�Ů����һ����������������������ˣ�˵�ŰѴ����˻�ȥ��\n",this_object());
        set("temp/snake_hole", 0);
}

void do_wugu_therapy_down(object me)
{
        object npc;
        message("vision","����һ�ᣬ������������˴���������Ѫ��ȴ��֪����ȥ�ˡ���\n",this_object());
        npc = new(__DIR__"npc/wugu");
        npc->move(this_object());
        set("in_wugu_therapy",0);
        set("temp/snake_hole", 0);
        me->set_temp("kunlun/help_wugu",1);
}
