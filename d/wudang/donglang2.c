// Room: donglang2.c ��������

inherit ROOM;

void init();
void close_men();
void force_open(object room);
int do_push(string arg);
int do_knock(string arg);
int valid_leave(object me, string dir);
string look_men();

void create()
{
    set("short", "��������");
    set("long", @LONG
������һ�������ϣ���Լ�����������ߴ������������ƺ�������������������
������һ���ţ�men���������������š��ϱ��Ǽ��������͵����ӣ�ʮ�ֵ����ţ�
����Ʈ��һ����Ĳ��㣬��������ϸ��ز�֪˵��Щʲô������Ů���ӣ��Գԣ�
Ц��������
LONG );

    set("exits", ([
        "east" : __DIR__"liangongfang",
        "south" : __DIR__"chashi",
        "west" : __DIR__"donglang1",
            "north" : "/d/wudang/xiuxishi",
    ]));

    set("item_desc",([
        "men"        :    (: look_men :),
    ]));

    set("no_clean_up", 0);
    setup();
}

void init()
{
    add_action("do_knock", "knock");
    add_action("do_push", "push");
}

void close_men()
{
    object room;

    if(!( room = find_object(__DIR__"xiuxishi")) )
        room = load_object(__DIR__"xiuxishi");
    if(objectp(room))
    {
        delete("exits/north");
        message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", this_object());
        room->delete("exits/south");
        message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", room);
    }
    else message("vision", "ERROR: men not found(close).\n", room);
}

int do_knock(string arg)
{
    object room;

    if (query("exits/north"))
        return notify_fail("�����Ѿ��ǿ����ˡ�\n");

    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("��Ҫ��ʲô��\n");

    if(!( room = find_object(__DIR__"xiuxishi")) )
        room = load_object(__DIR__"xiuxishi");

    if(objectp(room))
    {
    if ((int)room->query_temp("sleeping_person") > 0)
    {
        message_vision(
        "$N�����������һ���ţ����������洫��һ���������������\n"
        "��Ȼ�������˯�ø������Ƶģ���ô�ö�û����\n",
        this_player());
    } else if ((int)room->query_temp("person_inside") > 0)
    {
        switch( random(2) )
        {
        case 0:
                message_vision(
                "$N������������ţ�ֻ�����������˺ܲ��ͷ��غ𵽣�\n"
                "�����¾������ţ���˯���ˣ�������������\n",
                this_player());
        case 1:
                message_vision(
                "$N������������ţ�ֻ����������Щ�춯��\n"
                "����������������ȥ���ò��������Ƿ��š�\n",
                this_player());

                break;
        }

    } else
    {
        room->delete_temp("sleeping_person");
        message_vision("$N������������ţ��ˡ��ˡ��ˣ������ˡ��ˡ��ˣ�����\n",
            this_player());
    }
    }

    if(objectp(room))
        message("vision",
        "���洫��һ��������������ŷ�����һ�ƣ���"+this_player()->query("name")+
"һ��������վ�����⣬\n"
        "������Ҳ�������Ϣ��\n", room);
    return 1;
}

int do_push(string arg)
{
    object room;

    if (query("exits/north"))
        return notify_fail("���Ѿ��ǿ����ˡ�\n");

    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("��Ҫ��ʲô��\n");

    if(!(room = find_object(__DIR__"xiuxishi")))
        room = load_object(__DIR__"xiuxishi");

    if(objectp(room))
    {
    if((int)room->query_temp("person_inside")<=0)
    {
                room->delete_temp("person_inside");
        set("exits/north", __DIR__"xiuxishi");
        message_vision("$N����ذ����ƿ���\n", this_player());
        room->set("exits/south", __FILE__);
//      message("vision", "���˴���������ƿ��ˡ�\n", room);
        remove_call_out("close_men");
        call_out("close_men", 10);
    } else
    {
        message_vision("$N������ƿ���ȴ�����ű��˴����������ˡ�\n",
                this_player());
    }
    }

    return 1;
}


string look_men()
{
    object room;

    if (query("exits/north"))
        return ("���Ϲ��˸����ӣ��Ͽ��δ�\n");

    if(!( room = find_object(__DIR__"xiuxishi")) )
        room = load_object(__DIR__"xiuxishi");

    if( objectp(room) )
    if( (int)room->query_temp("person_inside") > 0 )
    {
        return ("���Ϲ��˸����ӣ��������\n");
    }

    return ("���Ϲ��˸����ӣ���Ϣ��\n");
}

int valid_leave(object me, string dir)
{

        object room;

        if(!( room = find_object(__DIR__"xiuxishi")) )
                room = load_object(__DIR__"xiuxishi");

        if(objectp(room) && dir == "north")
        {
                room->add_temp("person_inside", 1);
                // will open the door if ppl inside stay too long
                remove_call_out("force_open");
                call_out("force_open", 599, room);
        }

        return ::valid_leave(me, dir);
}

void force_open(object room)
{
        if ( !objectp(room) ) return 0;
    if((int)room->query_temp("person_inside")<=0) return 0;

/***
    if((int)room->query_temp("sleeping_person")>0)
    {
                remove_call_out("force_open");
                call_out("force_open", 599, room);
                return 0;
        }
***/

        room->delete_temp("person_inside");
    set("exits/north", __DIR__"xiuxishi");
    room->set("exits/south", __FILE__);
    message("vision", "����ͻȻ������صĽŲ�������Զ����������ǰͣ������������\
n"
        "����Ϫž�ذ��Ŵ򿪣����ͷ������һ�����ɣ���������˻�����ȥ����ʲô��
�\n", room);
    remove_call_out("close_men");
    call_out("close_men", 10);
}
