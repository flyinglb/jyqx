// Room: /d/gaochang/room74.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "�ͱ�");
        set("long", @LONG
���ֱ�����������λ�ڰ�ɽ�����ͱ��ϡ����ܶ��ǻ�ѩ�������ĸ���
�������亣������滨��������̣�����ӳ�̣�����Ϧ�����ӳ�գ���
�޻�����������״��
LONG
        );
    if (random(10)>7)
    set("objects", ([
           __DIR__"obj/youtan":2,
    ]));
    else delete("objects");


        setup();
}
void init()
{
   object me=this_player();
   if (!wizardp(me))
        call_out("drop",3,me);
}
void drop(object me)
{
    object room;
    if (!me || environment(me)!=this_object())    return;
    if (!(room=find_object(__DIR__"room50")))
        room=load_object(__DIR__"room50");
    message_vision("ֻ��������֦����һ������������$N�����أ�Ӧ�����ϣ�\n",me);
    me->move(room);
    me->receive_wound("qi",200);
    message("vision","���һ����"+me->name()+"������ˤ��������\n",room,({me}));
}

