// Roon: ziqitai.c
//Date: Oct. 2 1997 by Venus
inherit ROOM;

void create()
{
        set("short", "����̨");
        set("long", @LONG
����̨�����������ڣ����ɲ������գ���Ϊ������ǣ�û������
�죬ɽ��֮�о��������������֡�
LONG);
        set("outdoors", "xx");
        set("exits",([ /* sizeof() == 1 */
            "eastdown": __DIR__"chaopath2",
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        object me;
        me=this_player();
        if (me->query_dex() > 40)
             this_object()->set("exits/down", "/d/jinshe/shanbi");
	else
             this_object()->delete("exits/down");
        remove_call_out("close");
        call_out("close", 5, this_object());
        return;
}
void close(object room)
{
        this_object()->delete("exits/down");
        return;
}
