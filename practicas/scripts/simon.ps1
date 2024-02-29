# Definimos una lista de colores (puedes agregar más si lo deseas)
$colores = @("Red", "Green", "Blue", "Yellow")

# Generamos una secuencia aleatoria de colores
$secuenciaAleatoria = Get-Random -InputObject $colores -Count 5

# Mostramos la secuencia al usuario
Write-Host "¡Atención! Simón dice:"
$secuenciaAleatoria | ForEach-Object {
    Write-Host $_ -ForegroundColor $_
    Start-Sleep -Seconds 1
    Clear-Host
}

# El usuario debe repetir la secuencia
Write-Host "Repite la secuencia ingresando los colores uno por uno:"

# Leemos la entrada del usuario
$entradaUsuario = Read-Host "Ingresa los colores separados por comas"

# Convertimos la entrada del usuario en un arreglo
$entradaUsuario = $entradaUsuario -split ","

# Comparamos la entrada del usuario con la secuencia original
if ($entradaUsuario -eq $secuenciaAleatoria) {
    Write-Host "¡Excelente! Has repetido correctamente la secuencia."
} else {
    Write-Host "¡Oops! Algo salió mal. Inténtalo de nuevo."
}
