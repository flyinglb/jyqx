inherit F_CLEAN_UP;
object find_env(object ob);
#define MAX_DIS 7
#define MAX_ALT  2
#define MAX_DIR  8
int main(object me, string str)
{
        string output = "";
        if(!str) return notify_fail("指令格式: locate <物品>\n");
        me->add("sen",-5);
        output = TASK_D->locate_obj(me,str);
        if(output=="")
                return notify_fail("确定不了"+str+"的大概位置。\n");
        write(output);
        return 1;
}
int help(object me)
{
        write(@HELP
指令格式: locate <物品>
这个指令是用来得知使命物品的大概位置。
HELP
        );
        return 1;
}
object find_env(object ob)
{
        while(ob)
        {
        if(ob->query("coor") ) return ob;
        else ob=environment(ob);        
        }
        return ob;
}
