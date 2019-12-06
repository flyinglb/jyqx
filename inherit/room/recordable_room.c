// Recordable_room.c �ɼ�¼����
// Written by Doing Lu 1998/11/16
//    �ɼ�¼��������ܹ�����������ݵ�����������Ҫ���ṩ��������Ҫ�������Ա仯�ĵ�
//    �����������ѡ�Ľ����ص㡣��MUDLIB�й������ROOM�Ĳ���Ҫ�ϸ���ƣ���Ϊ�⽫��
//    ��MUDLIB�ĳ������Ͻ����Ź۵������ͻ�����ϵͳ�������������������֣���ˣ�����
//    ����������Եĳ����������Ҫ�޸�ʱ��Ӧ���ϱ���ʦ����arch���ϵ���ʦ��׼�󷽿�
//    �����޸Ĳ�����
//
//    �ڼ̳�Recordable_room ʱ�������init����������̳�ʹ�������ṩ��init��������
//    init������Ӧ����::init�ĵ��ã����Ҳ���ʹ��replace_room������
inherit ROOM;
inherit F_SAVE;

mapping user_room;

// ���������췿������ݣ�mapping ��ŵ��� ������ : ��ڵ��ļ�·��
// ���磺���ξ� : /d/room/doing/????.c

// ����object�浵������
string query_save_file()
{
/*
        string file;
        string basen;
*/

        return "/data/room" + base_name(this_object()) + ".sav";
}

// ����long����������xiaoyuan������
void create_desc()
{
        string  desc, ext_long;
        string* uroom;
        int     count;
        int     i;

        delete("item_desc/xiaoyuan");
        ext_long = "";
        if (mapp(user_room))
        {
                // ������ｨ�з��䣬�޸�long����ʾ��Ϣ
                count = 0;
                desc = "���������";
                uroom = keys(user_room);
                for (i = 0; i < sizeof(uroom); i++)
                {
                        if (!stringp(uroom[i]) || uroom[i] == "") continue;
                        count++;
                        if (count > 1)
                        {
                                if ((count-1) % 4 == 0) desc += "\n          ";
				else desc += "\t";
                        }
                        desc += uroom[i];
                }
                desc += "��";
                if (count > 0)
                {
                        if (count > 1)
                        {
                                ext_long = "    ��������ԼԼ�����ż���СԺ(xiaoyuan)��\n";
                        } else
                        {
                                ext_long = "    ��������ԼԼ��������һ��СԺ(xiaoyuan)��\n";
                        }
                        set("item_desc/xiaoyuan", desc + "\n");
                }
        } else
        {
                // ���û�ж���user_room, ��Ϊ��
                user_room = ([ ]);
        }
        set("long", query("old_long") + ext_long);
}

// ��ȡ��¼�����ݣ����Ҹ�������Խ��ķ��������ʾ��Ϣ
//int setup()
void setup()
{
        string old_long;

        old_long = query("long");
        if (file_size(query_save_file() + __SAVE_EXTENSION__) != -1)
        {
                // ����д浵��ȡ�浵����
                restore();
        }
        set("old_long", old_long);
        set("recordable_room", 1);
        create_desc();

        ::setup();
}

// ��ʼ������ʱ��״̬
void init()
{
        // ���ӽ��뷿��ĺ���
        add_action("do_enter", "enter");
        add_action("do_enter", "����");
}

// ����һ�׷���
int create_room(string room_name, string path)
{
        if (! mapp(user_room)) user_room = ([ ]);
        if (! stringp(room_name) || room_name == "") return 0;
        if (! undefinedp(user_room[room_name])) return 0;
        user_room[room_name] = path;
        create_desc();
        return 1;
}

// �ж��Ƿ����һ�׷���
int exist_room(string room_name)
{
        if (! mapp(user_room)) return 0;
        if (! stringp(room_name) || room_name == "") return 0;
        if (undefinedp(user_room[room_name])) return 0;
        return 1;
}

// ȥ��һ�׷���
int demolish_room(string room_name)
{
        if (! mapp(user_room)) return 1;
        if (! stringp(room_name) || room_name == "") return 0;
        if (undefinedp(user_room[room_name])) return 0;
        map_delete(user_room, room_name);
        create_desc();
        return 1;
}

// ����һ�׷������ڴ�
int do_enter(string room_name)
{
        object me;
        object ob;

        me = this_player();
        if (! stringp(room_name) || room_name == "" ||  ! mapp(user_room))
        {
                return notify_fail("����ȥ���\n");
        }
        if (undefinedp(user_room[room_name]))
        {
                tell_object(me, "�������ҿ�����Ҳû�ҵ��ǵط���\n");
                message("vision", me->query("name") +
                        "�����ҿ������������Ĳ�֪���ڸ�Щʲô��\n", environment(me), ({me}));
                return 1;
        }
        if (! (ob = find_object(user_room[room_name])))
        {
                ob = load_object(user_room[room_name]);
                if (! objectp(ob))
                {
                        write (user_room[room_name] + "\n");
                        message_vision("$N�첽��" + room_name + "��ȥ�����һͷײ������...������ʦ������\n", me);
                        return 1;
                }
        }
        tell_object(me, "��첽��" + room_name + "��ȥ��\n");
        message("vision", me->query("name") +
                        "��" + room_name + "ƮȻ��ȥ��\n", environment(me), ({me}));
        me->move(ob);
        return 1;
}
