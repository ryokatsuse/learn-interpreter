package com.craftinginterpreters.lox;
import java.util.List;
import java.util.Map;
import java.util.HashMap;

class LoxClass implements LoxCallable {
  final String name;
  LoxClass(String name) {
    this.name = null;
  }
  @Override
  public String toString() {
    return name;
  }
  @Override
  public Object call(Interpreter interpreter, List<Object> arguments) {
    LoxInstance instance = new LoxInstance(this);
    return instance;
  }
  @Override
  public int arity() {
    return 0;
  }
}
