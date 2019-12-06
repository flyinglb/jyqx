// private_room.c
// Written by Doing Lu 1998/11/16
//    ˽�з������ṩ����ҵķ�����Ҫ�̳е����ԣ�����Ҫ�������µ�����:
//    ���ȣ������Ҫ���ʱ(clean_up������)����Ҫ�������������������ڵ����п���
//    �������Ʒ(����AUTOLOAD���Ե�)��
//    ��Σ�����������load��ʱ���Զ��ĵ��뱣���ڴ����ϵĶ������ݣ���Ȼ����Ҫ���
//    �Ƿ��д������ݡ�

// ����ļ��̳���ԭ�е�ROOM�����޶���һЩ������

#include <room.h>

inherit ROOM;
inherit F_SAVE;
inherit F_AUTOLOAD;

// ����object�浵������
string query_save_file()
{
        string file;
        file = base_name(this_object()) + ".sav";
        if (file[0..10] != "/data/room/") file = "/data/room" + file;

        return file;
}

// save���̿��Ա�����������ڵ�����autoload����Ʒ��
int save()
{
        // ��������⣬����洢
        if (query("outdoors")) return 1;

        save_autoload();
        return ::save();
}

// �ظ������ڵ���Ʒ
int restore()
{
        // ��������⣬�����ȡ
        if (query("outdoors")) return 0;

        ::restore();
        return restore_autoload();
}

// ����һ���ǳ���Ҫ�ĺ�����ϵͳÿ��һ��ʱ��(ͨ����15����)�ͻ�������������
// �������0��ϵͳ�����ٵ������������������ص���1��������һ������������
// ������
int clean_up()
{
        object *inv;
        int i;

        // ����������������ҾͲ����
        inv = all_inventory();
        for(i=sizeof(inv)-1; i>=0; i--)
                if(interactive(inv[i])) return 1;

        // ���沢����������
        save();
        destruct(this_object());
        return 0;
}

// ��������
//int setup()
void setup()
{
        // ����˽�з����־
        set("private_room", 1);

        ::setup();

        if (! query("outdoors") && file_size(query_save_file() + __SAVE_EXTENSION__) != -1)
        {
                // ����д浵���������ڣ���ȡ�浵����
                restore();
        }
//        return 1;
}

// �����̳е�ROOM
string look_door(string dir)
{
        if( !mapp(doors) || undefinedp(doors[dir]) )
                return "��Ҫ��ʲô��\n";
        if( doors[dir]["status"] & DOOR_CLOSED )
                return "���" + doors[dir]["name"] + "�ǹ��ŵģ�������һ��Կ�׿ס�\n";
        else
                return "���" + doors[dir]["name"] + "�ǿ��ŵġ�\n";
}

// �����̳е�ROOM
varargs int open_door(string dir, int from_other_side)
{
        mapping exits;
        object ob;
        object me;

        if( !mapp(doors) || undefinedp(doors[dir]) )
                return notify_fail("�������û���š�\n");

        if( !(doors[dir]["status"] & DOOR_CLOSED) )
                return notify_fail( doors[dir]["name"] + "�Ѿ��ǿ��ŵ��ˡ�\n");

        exits = query("exits");
        if( !mapp(exits) || undefinedp(exits[dir]) )
                error("Room: open_door: attempt to open a door with out an exit.\n");

        if( from_other_side )
        {
                message("vision", "���˴���һ�߽�" + doors[dir]["name"] + "���ˡ�\n", this_object());
        }
        else
        {
                me = this_player();
                if (! stringp(query("key")) || ! objectp(ob = present(query("key"), me)))
                {
                        message_vision("$N��ǰ�����ƣ���������˿������\n", me);
                        return notify_fail("��������ҵ�Կ�ײ��С�\n");
                }
                if (! objectp(ob = find_object(exits[dir])));
                        ob = load_object(exits[dir]);
                if (! objectp(ob)) return 0;

                if (! ob->open_door(doors[dir]["other_side_dir"], 1) ) return 0;

                message_vision("$N�ͳ�Կ�ף�����Կ�׿�Ť�˼��¡�\n", me);
        }
        doors[dir]["status"] &= (!DOOR_CLOSED);
        return 1;
}
