// didao3.c
inherit ROOM;
void cloth_path();
void create()
{
        set("short", "÷ׯ�ܵ�");
        set("long", @LONG
����һ���谵��ʪ�ĵص����ص��ܳ������ߵ���������̫������
��ѣ��ص����Ե�ǽ���ϻ��źܶ಻֪�����Ժ���֮�ֵıڻ�������
�����൱�ѿ�����ӿ�Ų�����֪���ص��ľ�ͷ��ʲô�ط���ͻȻ֮
���㷢������ĵ����Ѿ���ľ��ƴ�ɵ��ˡ�
LONG
        );
        set("exits", ([
            "south" : __DIR__"didao2",
        ]));
        set("item_desc", ([
                "floor": "���ľ���ƺ���������(pull)��\n",
        ]) );

        setup();
}
void init()
{
        add_action("do_open", "pull");
}
int do_open(string arg)
{
//        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "floor")
        {
        me = this_player();
        message_vision("$N������ϵ�ľ�壬���������ǿյġ�\n", me);
        if( !query("exits/down") ) {
        set("exits/down", __DIR__"didao4");
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("�㲻���Դ�"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/down") ) return;
        message("vision",
"ľ���ֵ��˻�������ס��������ܵ���\n",
                this_object() );
                delete("exits/down");
}

