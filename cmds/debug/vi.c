// /cmds/wiz/me.c
//
// Kenny@Broken.History (6/18/1996)

inherit F_CLEAN_UP;
inherit F_VI;                           // �̳б༭����

int file_exists(string file);

int main(object me, string arg)
{
        string file, oldfile;
        object ob;

        if (in_edit(me)) return notify_fail("���Ѿ���ʹ�ñ༭���ˡ�\n");
        if (!arg) return notify_fail("ָ���ʽ��me <����>|<�����>\n");

        seteuid(geteuid(me));
        file = resolve_path(me->query("cwd"), arg); // ȡ�õ���
        if (!file_exists(file)) // check virtual object
        {
                string *path=explode(file, "/");
                oldfile = file;
                file = "/"+implode(path[0..<2], "/")+"/_"+path[<1];
        }
        if (!file_exists(file))
        {       // �µ�
                ob = present(arg, me);  // ������ϵ����
                if (!ob) ob = present(arg, environment(me)); // ��鷿��������
                if (ob && me->visible(ob))
                        file = base_name(ob) + ".c"; // ȡ������ĵ���
                else    file = oldfile;
        }

        start_edit(file);               // ���б༭������ʼ�༭
        return 1;
} // main()

int file_exists(string file)
{
        if (!stringp(file) || file=="") return 0;
        return file_size(file)>=0;
}

int  help(object me)
{
        write(@HELP
ָ���ʽ��me <����>|<�����>

���ô�һָ���ֱ�������ϱ༭��������ϸ˵���뿴�༭���ڵ����ϸ���˵����

���ָ�edit��update��
HELP
                );
        return 1;
} // help()
