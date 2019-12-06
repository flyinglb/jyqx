// user.c

inherit F_CLEAN_UP;

int main(string str)
{
        object *ob,env;
        int i;

        ob=children(USER_OB);
        i = sizeof(ob);
        while (i--) {
                env = environment(ob[i]);
                write(sprintf("%15s : %30s :%O\n",ob[i]->query("id"),
                file_name(ob[i]),env));
        }
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : user

将所有玩家的/obj/user number 显示出来。
HELP
    );
    return 1;
}
