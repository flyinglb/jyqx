// passwd.c
// by long
// modified by wind

#include <ansi.h>
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me,string name)
{
        object ob,body;
        if(!name) return notify_fail("ָ���ʽ��setpass <sb>\n");
        if(objectp(body = find_player(name)) && geteuid(body)==name)
               return notify_fail("���Ŀǰ�����ϣ�û���޸ı�Ҫ�ɡ�\n");
        ob = new(LOGIN_OB);
        ob->set("id", name);
        if(!ob->restore()) return notify_fail("û�������ҡ�\n");
        write("�����޸�"+ob->query("name")+"("+ob->query("id") +")�����롣\n");
        write("�������µ����룺");
        input_to("input_pass1",1,ob);
        return 1;

}
void input_pass1(string pass1,object ob)
{
        write("\n��ȷ�������룺");
        input_to("input_pass2",1,ob,crypt(pass1,0));
}
void input_pass2(string pass2,object ob,string pass1)
{
        write("\n");
        if(crypt(pass2,pass1) != pass1) write("��������������벻һ�£�ȡ���޸ġ�\n");
        else {
        ob->set("password",pass1);
        ob->save();
        write("��֪ͨ"+ob->query("id")+"���������룡\n");
        log_file("static/SETPASS", sprintf("[%s] %s set passwd of %s.\n",ctime(time())[0..15], geteuid(this_player(1)),ob->query("id")));
        }
        destruct(ob);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : setpass <sb>
HELP
    );
    return 1;
}

