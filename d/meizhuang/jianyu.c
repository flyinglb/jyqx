// jianyu.c
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", BLU"÷ׯ����"NOR);
        set("long", @LONG
����ںڰ������������ֲ�����ָ��Ψһ�Ĺ�������ǽ�Ϻ���������
���͵ơ����Ϻ�ǽ�ϲ����˰���ɫ��Ѫ�ۣ�ɢ�����������������ϴ�����
��Ϣ���������ĵ�����ص�������ë����Ȼ���ӵ��ε�ǽ����͸��������
�⡣
LONG
        );
        set("item_desc", ([
                "wall": "ǽ�ϵ���ʯש�ƺ���ǰ���˶���ʲô�ֽš�\n",
        ]) );
        set("objects", ([
                "/d/heimuya/npc/renwoxing" : 1,
        ]) );
        set("valid_startroom","1");

        setup();
}

void init()
{
        add_action("do_push", "push");
}

void check_trigger()
{
        object room;
        if( (int)query("trigger")==8 && !query("exits/out") )
        {
message("vision", "ǽ�ڱ����Ƶ��ѿ���һ����϶���պÿ����������ȥ��\n", this_object() );
                set("exits/out", __DIR__"xiaowu");
                if(!( room = find_object(__DIR__"xiaowu")) )
                     room = load_object(__DIR__"xiaowu");
                message("vision", "����ͻȻ�ѿ�һ��խ�졣\n", room );
                room->set("exits/enter", __FILE__);
                delete("trigger");
                call_out("close_passage", 5);
        }
}

void close_passage()
{
        object room;

        if( !query("exits/out") ) return;
        message("vision",
"һƬɳ��������, �ֽ�ͨ���ڸ�ס�ˡ�\n", this_object());
//        if( room = find_object(__DIR__"east_castle") ) {
        if( room = find_object(__DIR__"xiaowu") )
        {
message("vision", "һƬɳ�����������ֽ�ͨ���ڸ�ס�ˡ�\n", room );
                room->delete("exits/enter");
        }
        delete("exits/out");
}

int do_push(string arg)
{
//        string dir;

        if( !arg || arg=="" )
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }

        if( arg=="wall" || arg == "ǽ��")
        {
                add("trigger", 1);
                write("��������������ǽ���ϵ���ש���ƺ���һ���ɶ�....\n");
                check_trigger();
                return 1;
        }
}

void reset()
{
        ::reset();
        delete("trigger");
}

