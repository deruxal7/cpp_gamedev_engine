#!/bin/bash

# Скрипт сборки проекта.

BUILD_DIR="build"

echo "Начинаем сборку проекта..."

rm -rf "$BUILD_DIR"

mkdir -p "$BUILD_DIR" || { echo "Ошибка: Не удалось создать каталог сборки '$BUILD_DIR'" >&2; exit 1; }

cd "$BUILD_DIR" || { echo "Ошибка: Не удалось перейти в каталог '$BUILD_DIR'" >&2; exit 1; }

echo "Запускаем CMake..."
cmake .. 2>&1 | tee cmake.log

if [ $? -ne 0 ]; then
  echo "Ошибка: CMake завершился с ошибкой. Смотрите cmake.log для подробностей." >&2
  exit 1
fi

echo "CMake успешно завершен!"
echo ""

echo "Запускаем сборку..."

make -j "$(nproc)" 2>&1 | tee make.log

if [ $? -ne 0 ]; then
  echo "Ошибка: Make завершился с ошибкой. Смотрите make.log для подробностей." >&2
  exit 1
fi

echo "Сборка успешно завершена!"
echo ""

EXECUTABLE="./CacTusEngine"

if [ -x "$EXECUTABLE" ]; then
  echo "Запускаем проект..."
  "$EXECUTABLE"
else
  echo "Ошибка: Исполняемый файл '$EXECUTABLE' не найден или не является исполняемым." >&2
  exit 1
fi

cd ..

# Удаляем каталог сборки. Это опционально.  В большинстве случаев его полезно сохранить для повторных сборок.  Закомментировано по умолчанию.
# echo "Удаляем каталог сборки..."
# rm -rf "$BUILD_DIR"

echo "Сборка завершена."

exit 0