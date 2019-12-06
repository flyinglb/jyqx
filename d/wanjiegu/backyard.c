// Room: /t/wanjiegu/backyard.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
��Ժ��һ��Ƭ�����Ĳݵأ��̲����񣬼���Ұ����׺��䣬��
���м����һ���ʯ�̳ɵ����̣�һ����ü��ɮ��һ�����ۿ�����
���塣������һ��ʯ�ݣ��ſڱ�һ���ʯͷ��ס�ˡ�
LONG
        );
        set("outdoors", "wanjiegu");
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"hall",
        ]));
        set("objects", ([
            __DIR__"npc/monk" : 1,
            __DIR__"npc/duan_yanqing" : 1,
        ]));
        set("no_clean_up", 0);
        set("item_desc", ([ /* sizeof() == 2 */
            "��ʯͷ" : "һ��ܴ��ʯͷ����ס��ʯ�ݵ���ڡ�\n",
            "rock" : "һ��ܴ��ʯͷ����ס��ʯ�ݵ���ڡ�\n",
        ]));

        setup();
}

void init()
{
        add_action("do_push","push");
}

void check_trigger()
{
//        object room;
        if( (int)query("trigger")==9
        &&      !query("exits/north") ) {
                message("vision",
HIW "��ʯ���ڱ��ƿ��ˣ�¶��ͨ��ʯ�ݵ�ͨ����\n" NOR,
                        this_object() );
                set("exits/north", __DIR__"stone_room");

                delete("trigger");
        }
}

int do_push(string arg)
{
//        string dir;
        object me = this_player();

        if( me->is_busy() ) {
             message_vision("�����һ��������û����ɣ�\n", me);
             return 1;
        }

        if( !arg || arg=="" )
        {
             write("��Ҫ��ʲô��\n");
             return 1;
        }

        if( arg=="rock" || arg == "��ʯͷ" ) {
             if ( me->query("str") + me->query("neili_factor") < 15 ) {
                tell_object(me,"�������̫С�ˣ��õ��������Կ���\n");
                return 1;
             }
             me->start_busy(2);
             message_vision(HIW "$N���˵���������ƶ���ʯͷ��\n" NOR,me);
             call_out("pushstone",2,me);
             me->stop_busy();
             check_trigger();
             return 1;
             }
}

int pushstone(object me)
{
        if(me->query("neili") >= me->query("neili_factor") ) {
                message_vision(HIW "��ʯͷ����һ�¡�\n" NOR,me);
                me->add("neili",- me->query("neili_factor") );
                add("trigger", 1);
                return 1;
        } else {
                tell_object(me, "������������ˣ���Ϣһ�����ưɣ�\n");
                return 1;
        }
}

void reset()
{
        ::reset();
        delete("trigger");
        delete("exits/north");
}

