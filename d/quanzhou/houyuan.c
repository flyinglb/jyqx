// room: houyuan.c
// Jay 4/8/96
#include <room.h>

inherit ROOM;
int do_break(string arg);
int look_tai(string arg);

void create()
{
        set("short", "��լ��Ժ");
        set("long", @LONG
������������լ�ĺ�Ժ�������Ƿ�������ù������Ҷ��Ժ�ӵ�������һ�ھ���
��̨(tai)�Ͽ���Щ�֡�Ժ��������һ����(men)�����ѱ�̮����ש�ߵ�ס
�ˡ�
LONG );
        set("exits", ([
            "down" : __DIR__"well",
        ]));
        set("item_desc", ([
                "men" : "�������ѱ���ס�޷�ͨ�У����������(break)����\n",
                "tai" : (:look_tai:),
        ]) );
	set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_break", "break");
        add_action("look_tai", "look");
}

int do_break(string arg)
{
        int n;
        n = this_player()->query("neili");
        if( !arg || arg!="men" ) {
                write("��Ҫ��������˵Ķ�����\n");
                return 1;
        }
        message_vision(
"$N�ߵ�����ǰ���ݳ��������ʽ������һ������˫��ͬʱ�ĳ���\n", this_player());
        
        if (n>=200) {
            message_vision(
            "$Nֻ��һ�����죬$N�������ˣ�\n", this_player());
            set("exits/south", __DIR__"laozhai");
            this_player()->set("neili",n-200);
            remove_call_out("close");
            call_out("close", 5, this_object());
        }
        else {
            message_vision(
"$N���һ���������������ʲôҲû����������$N����������ǿ��\n", this_player());
            this_player()->set("neili",0);
        }
        return 1;
}

void close(object room)
{
        message("vision","���ϵ�שͷ�߿�ϡ�ﻨ��̮���������ֵ�ס��С�š�\n", room);
        room->delete("exits/south");
}

int look_tai(string arg)
{
        if( !arg || arg!="tai" ) return 0;
        write("��̨�Ϻ��ҿ�������໰������һ���ǣ�\n");
        switch (random(15)) {
        case 0:
          write("�ּ�ûһ���ö������ҡ���Զͼ��������ƽ֮�����ڣ�\n");
          break;
        case 1:
          write("���������ҾͰ����Уңţӣӣ�������Щ����ӣ�\n");
          break;
        case 2:
          write("��ƽ֮���С����������Ȥ����ү�������������ү����������\n");
          break;
        case 3:
          write(this_player()->name()+"����̫���ˣ���ү�ҿ���һ�������Ҳû�С�\n");
          break;
        case 4:
          write("������Щ���ڱ��˼ҵľ�̨����Ϳ�໰��̫�����ˣ�\n");
          break;
        case 5:
          write("�٣����ӣ���ү����ľ����㣡\n");
          break;
        case 6:
          write("�ǣϡ����ȣţ��ģ������Σġ��ͣ��ˣš��ͣ١��ģ��٣�\n");
          break;
        case 7:
          write("������Ϊ�������Һ��뵱Ů���ϣ�\n");
          break;
        case 8:
          write("�����롡������������\n");
          break;
        case 9:
          write("����ں����ģ���û���������������Ҹ�"+this_player()->name()+"����\n");
          break;
        case 10:
          write("˵��������������ҿ����ˣ���\n");
          break;
        case 11:
          write(this_player()->name()+"�ʹ仨������Ϲ�㣡\n");
          break;
        case 12:
          write("ٯ��ֻ��ƨ�ۣ�\n");
          break;
        case 13:
          write("��������顡��ᡡ��塡��� ��\n");
          break;
        case 14:
          write("�Ҷ�����ĳ��\n");
          break;
        }
        return 1;
}

