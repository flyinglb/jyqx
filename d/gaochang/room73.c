// Room: /d/gaochang/room73.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
#include <room.h>
void init();
int do_pull(string arg);
void create()
{
        set("short", "����");
        set("long", "���ܺںڵģ�Ψ��������������͸��һ��"+BLINK+RED+"���"+NOR+"(hong guang)��\n");
    set("exits", ([ 
        "up" : __DIR__"room36",
]));
        setup();
}
void init()
{
    object *obj;
    obj=children(__DIR__"obj/wolfblade");
    set("blade",1);
    if (sizeof(obj)>1)  set("blade",0);
    if (query("blade")){ 
        set("long", "���ܺںڵģ�Ψ��������������͸��һ��"+BLINK+RED+"���"+NOR+"(hong guang)��\n");
        set("item_desc",(["hong guang":"�㷢�ֺ���Ȼ���Բ��ڵ��ϵ�һ�ѵ���\n",]));
        add_action("do_pull", "pull");
    }else{
        delete("item_desc");
        set("long", "���ܺںڵģ�ʲôҲû�С�\n");
    }
}
int do_pull(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (query("blade"))
        if( arg=="��" || arg=="blade") {
             ob=new(__DIR__"obj/wolfblade");
             if (!ob->move(me)) ob->this_object();
             message_vision("$N�γ�һ��"+RED+"Ѫ��"+NOR+"ɲʱ�����ʧ�ˣ����ܱ�úںڵġ�\n",me);
             set("long", "���ܺںڵģ�ʲôҲû�С�\n");
             delete("item_desc");
             set("blade",0);
             return 1;
        }
        return 0;
}

