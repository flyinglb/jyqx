//clone.c

#include "/doc/help.h"
inherit F_CLEAN_UP;

int main(object me, string file)
{

        object obj;
        string err, msg;

        seteuid( geteuid(me) );

        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail("��Ҫ����ʲ�������\n");

        file = resolve_path(me->query("cwd"), file);

        if( sscanf(file, "%*s.c") != 1 ) file += ".c";
        me->set("cwf", file);

        if( file_size(file) < 0 )
                return notify_fail("û���������(" + file + ")��\n");

        if( !find_object(file) ) {
                err = catch(call_other(file, "???"));
                if (err) {
                        write("����ʧ�ܣ�" + err + "\n");
                        return 1;
                }
        }
        err = catch(obj = new(file));

        if (err) {
                write("����ʧ�ܣ�" + err + "\n");
                return 1;
        }

        if( !stringp(msg = me->query("env/msg_clone")) )
                msg = "ֻ��$N�������һָ�������$n��\n";

        if( !obj->is_character() && obj->move(me) ) {
                log_file("static/clone", sprintf("%s%s clone %s (%s)\n",
                        me->query("name"),
                        "(" + me->query("id") + ")" ,
                        file,
                        ctime(time())
                        ) );
                write(obj->query("name") + "���Ƴɹ������������Ʒ����\n");
                message_vision(msg + "\n", me, obj);
                return 1;
        }

        if( obj->move(environment(me)) ) {
                log_file("static/clone", sprintf("%s%s clone %s (%s)\n",
                        me->query("name"),
                        "(" + me->query("id") + ")" ,
                        file,
                        ctime(time())
                        ) );
                write(obj->query("name") + "���Ƴɹ�������������䡣\n");
                message_vision(msg + "\n", me, obj);
                return 1;
        }

        destruct(obj);

        return notify_fail("�޷����Ʋ����ƶ������(" + file + ")��\n");
}

int help(object me)
{
  write(@HELP

ָ���ʽ : clone <����>

���ô�ָ��ɸ����κ����ƶ�֮���(������)��

HELP
    );
    return 1;
}
