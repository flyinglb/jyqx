int main(object me, string arg)
{
        object *objs = filter_array(objects(), (: userp :));
        for(int i = 0; i<sizeof(objs);i++) {
                object env = environment(objs[i]);
                write("User: "+objs[i]->short()+" Env: ");
                if(!env) write("0\n");
                else    write(env->short()+"\n");
        }
        return 1;
}
