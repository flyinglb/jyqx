// fangjian1.c
// by 2000.2.29

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Կ���������ǰ������һ������ĵط����������һ��ʯ������ֻ��
��֮�⣬�յ�����һ�����У�ʯ���Ͽ����ݺ�ʮ�ŵ���·������ϲ��Ŷ���
������ӣ�ȴ�Ǻڰ׶��ţ���Ȼ��һ��û��������塣
LONG );
        set("exits", ([
                "south" : __DIR__"shiji1",
        ]));
        set("no_clean_up", 0);
               setup();
}

void init()
{
        add_action("do_shout", "shout");
}

int do_shout(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="֥������") 
        {
                tell_object(me,"�����˵������ǽ�ڴ��һ������֥�����ţ���\n");
                if (random(100) >50 || ((me->query("family")) && me->query("family")["master_name"]=="��ң��"))
                {
                message("vision", "����һ�������ֻ����һ���¡¡��������������һ�����š�\n", me);
                set("exits/down", __DIR__"dazuo");
                remove_call_out("close");
                call_out("close", 5, this_object());
                }
        else
                {
                message("vision", "�����ﵽ���ص�����������������Ķ����������졣\n", me);
                me->receive_wound("qi",10);
                me->unconcious();
                }
                return 1;
        }
}

void close(object room)
{
        message("vision","һ���¡¡����������ʯ���ֻ����ع����ˡ�\n", room);
        room->delete("exits/down");
}


