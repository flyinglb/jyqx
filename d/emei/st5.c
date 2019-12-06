//Room: st5.c ��̶
//Date: Oct. 21 1997 by That
#include <ansi.h>

inherit ROOM;
void create()
{
    set("short","��̶");
    set("long",@LONG
���ܺ����ɣ�ʲô�������塣̶ˮ���Ŷ����ż��������һ������֪����
���޵Ŀݹǣ�����ȫ��ֱ��Ƥ�����Ư����ˮ�У������������鼱֮�£�
�Ĵ�����(wang)��
LONG);
    set("no_fight",1);
    set("no_sleep_room",1);
    set("objects", ([
        __DIR__"npc/frog" : 1,
    ]) );
    set("no_clean_up", 0);
    setup();
}
void init()
{
    add_action("do_wang", "wang");
}
int do_wang()
{
    object ob;
    ob = this_player();
    message_vision(HIC"$N��Ŀ���������Ƿ����г�·�ģ�����������֮̽�Ĵ󶯡�\n"NOR, ob);
    switch (random(4))
    {
       case 0 : set("exits/east", __DIR__"st5");break;
       case 1 : set("exits/east", __DIR__"st6");break;
       case 2 : set("exits/east", __DIR__"st4");break;
       default: set("exits/east", __DIR__"st4");
    }
    switch (random(4))
    {
       case 0 : set("exits/west", __DIR__"st5");break;
       case 1 : set("exits/west", __DIR__"st6");break;
       case 2 : set("exits/west", __DIR__"st7");break;
       default: set("exits/west", __DIR__"st8");
    }
    switch (random(4))
    {
       case 0 : set("exits/south", __DIR__"st5");break;
       case 1 : set("exits/south", __DIR__"st6");break;
       case 2 : set("exits/south", __DIR__"st7");break;
       default: set("exits/south", __DIR__"st8");
    }
    switch (random(4))
    {
       case 0 : set("exits/north", __DIR__"st5");break;
       case 1 : set("exits/north", __DIR__"st6");break;
       case 2 : set("exits/north", __DIR__"st7");break;
       default: set("exits/north", __DIR__"st8");
    }
    remove_call_out("close_out");
    call_out("close_out", 3);
    return 1;
}

void close_out()
{
    if (query("exits/east"))  delete("exits/east");
    if (query("exits/west"))  delete("exits/west");
    if (query("exits/south")) delete("exits/south");
    if (query("exits/north")) delete("exits/north");
}
