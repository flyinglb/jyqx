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
        if(!name) return notify_fail("指令格式：setpass <sb>\n");
        if(objectp(body = find_player(name)) && geteuid(body)==name)
               return notify_fail("玩家目前在线上，没有修改必要吧。\n");
        ob = new(LOGIN_OB);
        ob->set("id", name);
        if(!ob->restore()) return notify_fail("没有这个玩家。\n");
        write("下面修改"+ob->query("name")+"("+ob->query("id") +")的密码。\n");
        write("请输入新的密码：");
        input_to("input_pass1",1,ob);
        return 1;

}
void input_pass1(string pass1,object ob)
{
        write("\n请确认新密码：");
        input_to("input_pass2",1,ob,crypt(pass1,0));
}
void input_pass2(string pass2,object ob,string pass1)
{
        write("\n");
        if(crypt(pass2,pass1) != pass1) write("你两次输入的密码不一致，取消修改。\n");
        else {
        ob->set("password",pass1);
        ob->save();
        write("请通知"+ob->query("id")+"启用新密码！\n");
        log_file("static/SETPASS", sprintf("[%s] %s set passwd of %s.\n",ctime(time())[0..15], geteuid(this_player(1)),ob->query("id")));
        }
        destruct(ob);
}

int help(object me)
{
        write(@HELP
指令格式 : setpass <sb>
HELP
    );
    return 1;
}

